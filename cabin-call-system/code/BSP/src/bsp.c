/********************************Copyright (c)**********************************
**
**                   (c) Copyright 2019, Main, China, QD.
**                           All Rights Reserved
**
**                      		 XXXXXXXXX���޹�˾
**                           
**
**----------------------------------�ļ���Ϣ------------------------------------
** �ļ�����: bsp.c
** ������Ա: Andy
** ��������: 2021/4/03 15:40
** �ĵ�����: �������е���������ģ��
**
**----------------------------------�汾��Ϣ------------------------------------
** �汾����: V0.0.0.1
** �汾˵��: ��ʼ�汾
**
**------------------------------------------------------------------------------
*/
#include "bsp.h"


/*******************************************************************************
** ��������: ��ʼ��Ӳ���豸
** ����˵��: ��
** ����˵��: ��
** ������Ա: Andy
** ��������: 2021/4/03 14:45
**------------------------------------------------------------------------------
** �޸���Ա:
** �޸�����:
** �޸�����:
**------------------------------------------------------------------------------
********************************************************************************/
void bsp_Init(void)
{
	/* ��ʼ��lcd-1206�豸 */
	drv_lcd_1206_reg(bsp_software_delay_ms);
	
	return;
}

/*------------------------------------By_Andy_2021/4/03 15:35------------------------------*/
/*-----------------------------------------------------------------------------------------*/