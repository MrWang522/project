/********************************Copyright (c)**********************************
**
**                   (c) Copyright 2019, Main, China, QD.
**                           All Rights Reserved
**
**                      		 XXXXXXXXX���޹�˾
**                           
**
**----------------------------------�ļ���Ϣ------------------------------------
** �ļ�����: drv_lcd_1206a.h
** ������Ա: Andy
** ��������: 2021/4/03 15:40
** �ĵ�����: LCD1206A�ײ�����ģ��.h�ļ�
**
**----------------------------------�汾��Ϣ------------------------------------
** �汾����: V0.0.0.1
** �汾˵��: ��ʼ�汾
**
**------------------------------------------------------------------------------
*/
#ifndef _DRV_LCD_1206A_H_
#define _DRV_LCD_1206A_H_

/* ϵͳ���ļ� */
#include "sys.h"

/* LCD�˿ڶ��� */
#define LCD1206_RS 	 	P2^4	/* �Ĵ���ѡ���źţ�0-ָ��Ĵ��� 1-���ݼĴ��� */
#define LCD1206_RW		P2^5	/* ��д�ź�: 1-�� 0-д */
#define LCD1206_E			P2^6	/* Ƭѡ�źţ��������½����ź�ʱ��ִ��ָ��������� */
#define LCD1206_D			P0		/* 8λ˫��������*/

/* LCD��ʾλ��*/
#define LCD1206_FIRST_ROW     (0)
#define LCD1206_SECOND_ROW    (1)

/* ϵͳ΢����ʱ�������� */
typedef void (*pf_delay)(uint32_t);  

/* �ṩ������C�ļ����õĺ��� */
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
