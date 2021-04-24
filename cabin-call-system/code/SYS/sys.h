/********************************Copyright (c)**********************************
**
**                   (c) Copyright 2019, Main, China, QD.
**                           All Rights Reserved
**
**                      		 XXXXXXXXX���޹�˾
**                           
**
**----------------------------------�ļ���Ϣ------------------------------------
** �ļ�����: sys.h
** ������Ա: Andy
** ��������: 2021/4/03 15:40
** �ĵ�����: ϵͳ�ļ����е�h�ļ��Ļ����ļ�
**
**----------------------------------�汾��Ϣ------------------------------------
** �汾����: V0.0.0.1
** �汾˵��: ��ʼ�汾
**
**------------------------------------------------------------------------------
*/
#ifndef _SYS_H_
#define _SYS_H_

/* ϵͳ���ļ� */
#include <reg52.h>
#include <stdio.h>
#include <intrins.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* �ڵ��Խ׶Σ���STATIC����Ϊstatic��
   �汾����ʱ��Ϊ�գ��Ա��ں����Ĵ򲹶��Ȳ���*/
#ifdef _DEBUG
#define STATIC static
#else
#define STATIC
#endif

/* ������ʱ�� */
#define MAIN_Fosc 			11059200UL    

/* exact-width signed integer types */
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;

 /* exact-width unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;

/* �������󷵻��� */
enum{
	FUN_BACK_OK = 0,
	FUN_BACK_ERROR,
};

/* ϵͳ���󷵻��� */
enum{
	SYS_BACK_OK = 0,
	SYS_BACK_ERROR,
	
	/*add other ... */
	
	SYS_BACK_EXIT = 0x78, 
};

/* �ṩ������C�ļ����õĺ��� */
void bsp_software_delay_ms(uint32_t ms);

#endif

/*------------------------------------By_Andy_2021/4/03 15:35------------------------------*/
/*-----------------------------------------------------------------------------------------*/
