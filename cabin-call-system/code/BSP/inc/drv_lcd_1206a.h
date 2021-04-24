/********************************Copyright (c)**********************************
**
**                   (c) Copyright 2019, Main, China, QD.
**                           All Rights Reserved
**
**                      		 XXXXXXXXX有限公司
**                           
**
**----------------------------------文件信息------------------------------------
** 文件名称: drv_lcd_1206a.h
** 创建人员: Andy
** 创建日期: 2021/4/03 15:40
** 文档描述: LCD1206A底层驱动模块.h文件
**
**----------------------------------版本信息------------------------------------
** 版本代号: V0.0.0.1
** 版本说明: 初始版本
**
**------------------------------------------------------------------------------
*/
#ifndef _DRV_LCD_1206A_H_
#define _DRV_LCD_1206A_H_

/* 系统库文件 */
#include "sys.h"

/* LCD端口定义 */
#define LCD1206_RS 	 	P2^4	/* 寄存器选择信号：0-指令寄存器 1-数据寄存器 */
#define LCD1206_RW		P2^5	/* 读写信号: 1-读 0-写 */
#define LCD1206_E			P2^6	/* 片选信号，当输入下降沿信号时，执行指令或传送数据 */
#define LCD1206_D			P0		/* 8位双向数据线*/

/* LCD显示位置*/
#define LCD1206_FIRST_ROW     (0)
#define LCD1206_SECOND_ROW    (1)

/* 系统微秒延时函数类型 */
typedef void (*pf_delay)(uint32_t);  

/* 提供给其他C文件调用的函数 */
void drv_lcd_1206_clear(void);
void drv_lcd_1206_reg(pf_delay *fun);
void drv_lcd_1206_write_cmd(uint8_t cmd);
void drv_lcd_1206_read_data(uint8_t dt);
void drv_lcd_1206_set_pos(uint8_t size_x, uint8_t size_y);
void drv_lcd_1206_disp_char(uint8_t size_x, uint8_t size_y, uint8_t dat);
void drv_lcd_1206_disp_str(uint8_t size_x, uint8_t size_y, uint8_t *str);

#endif

/*------------------------------------By_Andy_2021/4/03 15:35------------------------------*/
/*-----------------------------------------------------------------------------------------*/
