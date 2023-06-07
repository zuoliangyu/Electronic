#include "beep.h"
#include "stm32f4xx_gpio.h"
#include "delay.h"


void Beep_Config(void)
{
	//使用PF8进行IO模拟
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能GPIOF时钟
  
	//初始化蜂鸣器对应引脚GPIOF8
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
	GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化GPIO
	
	GPIO_ResetBits(GPIOF,GPIO_Pin_8);  //蜂鸣器对应引脚GPIOF8拉低， 
	
	//延时初始化
	//Delay_Config(168);
}

void Beep_Num(uint32_t times)
{
	while(times--)
	{
		BEEP =1;
		Delay_ms(300);
		BEEP = 0;
		Delay_ms(300);
	}
}

