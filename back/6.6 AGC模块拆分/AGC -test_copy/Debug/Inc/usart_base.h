#ifndef _USART_BASE_H_
#define _USART_BASE_H_

#include <stdio.h>
#include "stm32f4xx_usart.h"

///////////////////////////////////////////////////////////////// 	 
//如果使用ucos,则包括下面的头文件即可.
#if SYSTEM_SUPPORT_UCOS
#include "includes.h"					//ucos 使用	  
#endif

//1-usart1, 2-usart2...
#define	USART	2
//#pragma message("use USART1")

extern u8  USART_RX_BUF[]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	

#define	USART_REC_LEN 	200  	//串口接受字符最大数

#if USART==1
#define	EN_USART1_RX		1		//使能串口中断接受
#elif USART==2
#define	EN_USART2_RX		1		//使能串口中断接受
#endif

#endif
