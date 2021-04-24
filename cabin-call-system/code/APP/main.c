/********************************Copyright (c)**********************************
**
**                   (c) Copyright 2019, Main, China, QD.
**                           All Rights Reserved
**
**                      		 XXXXXXXXX有限公司
**                           
**
**----------------------------------文件信息------------------------------------
** 文件名称: main.c
** 创建人员: Andy
** 创建日期: 2021/4/03 15:40
** 文档描述: AT89C52双直流电源切换系统：
**           
**----------------------------------版本信息------------------------------------
** 版本代号: V0.0.0.1
** 版本说明: 初始版本
**
**------------------------------------------------------------------------------
*/
#include "bsp.h"

sbit LED  = P3^5;
sbit KEY  = P3^6;
sbit BEEP = P3^7;

/*******************************************************************************
** 功能描述: 主函数:c程序入口
** 参数说明: 无
** 返回说明: 错误代码(无需处理)
** 创建人员: Andy
** 创建日期: 2021/4/03 14:45
**------------------------------------------------------------------------------
** 修改人员: wxd
** 修改日期: 2021/4/03
** 修改描述: 新作
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
	
	/* 默认为挂断状态 */
	KEY = 0;
	
	/* 初始化硬件设备 */
	bsp_Init();

	/* 显示提示信息：机舱呼叫系统 */
	drv_lcd_1206_disp_str(1, LCD1206_SECOND_ROW, "CABIN CALL SYS");
	bsp_software_delay_ms(300);
	drv_lcd_1206_clear();

	while(1)
	{
		/* 获取机舱类型及机舱号 */
		drv_keyboard_getval(&cabin_type, &cabin_num);
		
		/* 有机舱呼叫 */
		if(cabin_type && cabin_num && ((time_count==0) || (cabin_type == CLASS_BUSINESS)))
		{	
			BEEP = 0;
			
			/* 存入缓存 若检测为商务舱，则上锁 */
			carry[cabin_type-1][cabin_num-1] = 1;
			if(cabin_type == CLASS_BUSINESS)
			{
				lock = 1 << (cabin_num - 1);
			}
			
			BEEP = 1;
		}		
		
		/* 若为上锁状态 则优先处理商务舱 */
		(lock)?(j=1):(j=0);
		
		/* 机舱遍历 */
		for(i=0; i<5; i++)
		{
			if(carry[j][i] && (time_count == 0))
			{
				/* 清空该键缓存 */
				carry[j][i] = 0;	
				(j==1)?(lock &= ~(1 << i)):(lock=0);
				
				/* 开启1S定时器[时间显示] */
				time_count = 0;
				bsp_start_time();
				drv_lcd_1206_disp_str(sizeof("TYPE:"), LCD1206_FIRST_ROW, str_type[j+1]);
				drv_lcd_1206_disp_char(sizeof("SEAT:"), LCD1206_SECOND_ROW, i + 0x31);
				break;
			}
		}

		/* 定时1S时间到 */
		if(bsp_get_time_1s_sta())
		{	
			/* 声光报警提示 */
			LED = !LED;
			BEEP = !BEEP;
		
			/* 显示时间 */
			time_count++;
			sprintf(&time_display[0], "%d", time_count/10%10);		/* 十位 */
			sprintf(&time_display[1], "%d", time_count%10);			/* 个位 */
			drv_lcd_1206_disp_str(sizeof("TIME:")+8, LCD1206_SECOND_ROW, time_display);
		}
		
		/* 若时间到20s后自动挂断[最大显示99] */
		//if((time_count >= 20) || (KEY == 0))
		if(KEY == 0)
		{
			EA = 0;
			KEY = 1;
			LED = 1;
			BEEP = 1;
			time_count = 0;
			
			/* 清空屏幕显示 */
			drv_lcd_1206_disp_str(0, LCD1206_FIRST_ROW,  "TYPE: NONE    ");// 机舱类型
			drv_lcd_1206_disp_str(0, LCD1206_SECOND_ROW, "SEAT: -");		   // 机舱座位
			drv_lcd_1206_disp_str(8, LCD1206_SECOND_ROW, "TIME: --");      // 呼叫计时			
		}
	}
	
	return SYS_BACK_EXIT;
}

/*------------------------------------By_Andy_2021/4/03 15:35------------------------------*/
/*-----------------------------------------------------------------------------------------*/
