#ifndef _USART1_H_
#define _USART1_H_

#include "stm32f4xx.h"
#include "stdio.h"
#include "sys.h"
#include "usart_base.h"

typedef enum{DECIMAL, HEX} JINZHI;



extern uint8_t  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	

void USART1_Config(uint32_t  baudrate);
void USART1_Printf(const char* p,...);
void USART1_SendStrings(const unsigned char * str, size_t	size);
void USART1_SendNumber(uint32_t	num, uint8_t jinzhi);
#endif

