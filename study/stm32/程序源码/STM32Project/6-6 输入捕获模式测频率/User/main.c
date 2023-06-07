#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "PWM.h"
#include "IC.h"
#include "Serial.h"
uint32_t freq;
int main(void)
{
	PWM_Init();
	IC_Init();
	Serial_Init();
	PWM_SetPrescaler(720 - 1);			//Freq = 72M / (PSC + 1) / 100
	PWM_SetCompare1(50);				//Duty = CCR / 100
	while (1)
	{
		freq=IC_GetFreq();
		char String[100];
		sprintf(String, "\r\nfreq=%d", freq);
		Serial_SendString(String);
		Delay_ms(100);	
	}
}
