#include "usart.h"
#include "stm32f10x.h"

void usart_init(void)
{
	GPIO_InitTypeDef gpio_init;
	USART_InitTypeDef usartStruct;
	
	//1.ÅäÖÃÊ±ÖÓ£ºGPIO¿ÚµÄÊ±ÖÓ£¬Òý½Å¸´ÓÃµÄÊ±ÖÓ£¬´®¿ÚµÄÊ±ÖÓ
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	//2.ÅäÖÃGPIOµÄ½á¹¹Ìå
	//2.1 TX
	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_init.GPIO_Pin = GPIO_Pin_9;
	gpio_init.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init(GPIOA,&gpio_init);
	
	//2.2 RX
	gpio_init.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_init.GPIO_Pin = GPIO_Pin_10;
	
	GPIO_Init(GPIOA,&gpio_init);
	
	//3.ÅäÖÃ´®¿ÚµÄ½á¹¹Ìå
	usartStruct.USART_BaudRate = 115200;
	usartStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usartStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	usartStruct.USART_Parity = USART_Parity_No;
	usartStruct.USART_StopBits = USART_StopBits_1;
	usartStruct.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART1,&usartStruct);
	USART_Cmd(USART1, ENABLE );
	
}

//·â×°ÁËÒ»ÏÂ·¢ËÍ×Ö·û
void usartSendByte(USART_TypeDef* USARTx, uint16_t Data)
{
	USART_SendData(USARTx,Data);
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);

}

//·¢ËÍ×Ö·û´®
void usartSendStr(USART_TypeDef* USARTx,char *str)
{
	uint16_t i = 0;
	do{
		usartSendByte(USARTx,*(str+i));
		i++;
	}while(*(str+i) != '\0');

	//ÅÐ¶ÏÊÇ·ñ·¢ËÍÍê
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
}

int fputc(int ch,FILE *f)
{
	USART_SendData(USART1,(uint8_t)ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	
	return (ch);
}

