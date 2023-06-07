#include "beep.h"
#include "stm32f4xx_gpio.h"
#include "delay.h"


void Beep_Config(void)
{
	//ʹ��PF8����IOģ��
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ��GPIOFʱ��
  
	//��ʼ����������Ӧ����GPIOF8
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
	GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��GPIO
	
	GPIO_ResetBits(GPIOF,GPIO_Pin_8);  //��������Ӧ����GPIOF8���ͣ� 
	
	//��ʱ��ʼ��
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

