/********************************Copyright (c)**********************************
**
**                   (c) Copyright 2019, Main, China, QD.
**                           All Rights Reserved
**
**                      		 XXXXXXXXX有限公司
**                           
**
**----------------------------------文件信息------------------------------------
** 文件名称: sys.h
** 创建人员: Andy
** 创建日期: 2021/4/03 15:40
** 文档描述: 系统文件所有的h文件的汇总文件
**
**----------------------------------版本信息------------------------------------
** 版本代号: V0.0.0.1
** 版本说明: 初始版本
**
**------------------------------------------------------------------------------
*/
#ifndef _SYS_H_
#define _SYS_H_

/* 系统库文件 */
#include <reg52.h>
#include <stdio.h>
#include <intrins.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 在调试阶段，将STATIC定义为static，
   版本发布时改为空，以便于后续的打补丁等操作*/
#ifdef _DEBUG
#define STATIC static
#else
#define STATIC
#endif

/* 定义主时钟 */
#define MAIN_Fosc 			11059200UL    

/* exact-width signed integer types */
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;

 /* exact-width unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;

/* 函数错误返回码 */
enum{
	FUN_BACK_OK = 0,
	FUN_BACK_ERROR,
};

/* 系统错误返回码 */
enum{
	SYS_BACK_OK = 0,
	SYS_BACK_ERROR,
	
	/*add other ... */
	
	SYS_BACK_EXIT = 0x78, 
};

/* 提供给其他C文件调用的函数 */
void bsp_software_delay_ms(uint32_t ms);

#endif

/*------------------------------------By_Andy_2021/4/03 15:35------------------------------*/
/*-----------------------------------------------------------------------------------------*/
