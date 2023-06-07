#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "AD.h"
#include "usart.h"
#include "stdio.h"
uint16_t ADValue;
float Voltage;

int main(void)
{
	
	AD_Init();
	usart_init();
	
	while (1)
	{
		ADValue = AD_GetValue();
		Voltage = (float)ADValue / 4095* 3.3;
		printf("V=%.2f\r\n",Voltage);
		Delay_ms(10);	
	}
}
