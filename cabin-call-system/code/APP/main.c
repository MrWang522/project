/********************************Copyright (c)**********************************
**
**                   (c) Copyright 2019, Main, China, QD.
**                           All Rights Reserved
**
**                      		 XXXXXXXXX���޹�˾
**                           
**
**----------------------------------�ļ���Ϣ------------------------------------
** �ļ�����: main.c
** ������Ա: Andy
** ��������: 2021/4/03 15:40
** �ĵ�����: AT89C52˫ֱ����Դ�л�ϵͳ��
**           
**----------------------------------�汾��Ϣ------------------------------------
** �汾����: V0.0.0.1
** �汾˵��: ��ʼ�汾
**
**------------------------------------------------------------------------------
*/
#include "bsp.h"

sbit LED  = P3^5;
sbit KEY  = P3^6;
sbit BEEP = P3^7;

/*******************************************************************************
** ��������: ������:c�������
** ����˵��: ��
** ����˵��: �������(���账��)
** ������Ա: Andy
** ��������: 2021/4/03 14:45
**------------------------------------------------------------------------------
** �޸���Ա: wxd
** �޸�����: 2021/4/03
** �޸�����: ����
**------------------------------------------------------------------------------
********************************************************************************/
int main(void)
{	
	uint8_t cabin_type, cabin_num;
	uint32_t time_count = 0;
	uint8_t time_display[3] = "--";
	uint8_t carry[2][5] = { 0 };
	uint8_t i, j, lock = 0;
	uint8_t str_type[3][10] = {"NONE     ", "ECONOMY  ", "BUSINESS "};	
	
	/* Ĭ��Ϊ�Ҷ�״̬ */
	KEY = 0;
	
	/* ��ʼ��Ӳ���豸 */
	bsp_Init();

	/* ��ʾ��ʾ��Ϣ�����պ���ϵͳ */
	drv_lcd_1206_disp_str(1, LCD1206_SECOND_ROW, "CABIN CALL SYS");
	bsp_software_delay_ms(300);
	drv_lcd_1206_clear();

	while(1)
	{
		/* ��ȡ�������ͼ����պ� */
		drv_keyboard_getval(&cabin_type, &cabin_num);
		
		/* �л��պ��� */
		if(cabin_type && cabin_num && ((time_count==0) || (cabin_type == CLASS_BUSINESS)))
		{	
			BEEP = 0;
			
			/* ���뻺�� �����Ϊ����գ������� */
			carry[cabin_type-1][cabin_num-1] = 1;
			if(cabin_type == CLASS_BUSINESS)
			{
				lock = 1 << (cabin_num - 1);
			}
			
			BEEP = 1;
		}		
		
		/* ��Ϊ����״̬ �����ȴ�������� */
		(lock)?(j=1):(j=0);
		
		/* ���ձ��� */
		for(i=0; i<5; i++)
		{
			if(carry[j][i] && (time_count == 0))
			{
				/* ��ոü����� */
				carry[j][i] = 0;	
				(j==1)?(lock &= ~(1 << i)):(lock=0);
				
				/* ����1S��ʱ��[ʱ����ʾ] */
				time_count = 0;
				bsp_start_time();
				drv_lcd_1206_disp_str(sizeof("TYPE:"), LCD1206_FIRST_ROW, str_type[j+1]);
				drv_lcd_1206_disp_char(sizeof("SEAT:"), LCD1206_SECOND_ROW, i + 0x31);
				break;
			}
		}

		/* ��ʱ1Sʱ�䵽 */
		if(bsp_get_time_1s_sta())
		{	
			/* ���ⱨ����ʾ */
			LED = !LED;
			BEEP = !BEEP;
		
			/* ��ʾʱ�� */
			time_count++;
			sprintf(&time_display[0], "%d", time_count/10%10);		/* ʮλ */
			sprintf(&time_display[1], "%d", time_count%10);			/* ��λ */
			drv_lcd_1206_disp_str(sizeof("TIME:")+8, LCD1206_SECOND_ROW, time_display);
		}
		
		/* ��ʱ�䵽20s���Զ��Ҷ�[�����ʾ99] */
		//if((time_count >= 20) || (KEY == 0))
		if(KEY == 0)
		{
			EA = 0;
			KEY = 1;
			LED = 1;
			BEEP = 1;
			time_count = 0;
			
			/* �����Ļ��ʾ */
			drv_lcd_1206_disp_str(0, LCD1206_FIRST_ROW,  "TYPE: NONE    ");// ��������
			drv_lcd_1206_disp_str(0, LCD1206_SECOND_ROW, "SEAT: -");		   // ������λ
			drv_lcd_1206_disp_str(8, LCD1206_SECOND_ROW, "TIME: --");      // ���м�ʱ			
		}
	}
	
	return SYS_BACK_EXIT;
}

/*------------------------------------By_Andy_2021/4/03 15:35------------------------------*/
/*-----------------------------------------------------------------------------------------*/
