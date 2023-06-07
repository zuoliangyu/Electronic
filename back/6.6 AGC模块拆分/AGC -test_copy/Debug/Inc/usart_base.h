#ifndef _USART_BASE_H_
#define _USART_BASE_H_

#include <stdio.h>
#include "stm32f4xx_usart.h"

///////////////////////////////////////////////////////////////// 	 
//���ʹ��ucos,����������ͷ�ļ�����.
#if SYSTEM_SUPPORT_UCOS
#include "includes.h"					//ucos ʹ��	  
#endif

//1-usart1, 2-usart2...
#define	USART	2
//#pragma message("use USART1")

extern u8  USART_RX_BUF[]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		//����״̬���	

#define	USART_REC_LEN 	200  	//���ڽ����ַ������

#if USART==1
#define	EN_USART1_RX		1		//ʹ�ܴ����жϽ���
#elif USART==2
#define	EN_USART2_RX		1		//ʹ�ܴ����жϽ���
#endif

#endif
