#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
#include "Serial.h"
uint16_t ADValue;
float Voltage;

int main(void)
{
	
	AD_Init();
	Serial_Init();
	
	
	while (1)
	{
		ADValue = AD_GetValue();
		Voltage = (float)ADValue / 4095* 3.3;
		char String[100];
	sprintf(String, "\r\nv=%d", ADValue);
	Serial_SendString(String);
	Delay_ms(100);	
		
	}
}
