#include "led.h"
#include "stm32f4xx_gpio.h"

void LED_Config()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	/* GPIOC Peripheral clock enable */
  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//简单的电平输出可配置为OUT/IN模式,否则为AF
 	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOF, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//简单的电平输出可配置为OUT/IN模式,否则为AF
 	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOF, &GPIO_InitStructure);

	//探索者开发板采用的是类似共阳极的接法。
	//GPIO_ResetBits(GPIOF, GPIO_Pin_9);
	LED0 = 0;
	LED1 = 0;
}

