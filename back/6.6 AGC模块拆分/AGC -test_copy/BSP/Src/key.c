#include "key.h"
#include "stm32f4xx_gpio.h"
#include "stdio.h"
#include "delay.h"

void Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); // ʹ��GPIOFʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); // ʹ��GPIOFʱ��

#if KEY0_DEF
	// KEY0 ����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			 // ��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		 // ����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			 //
	GPIO_Init(GPIOE, &GPIO_InitStructure);						 // ��ʼ��GPIO
#endif

#if KEY1_DEF
	// KEY0 ����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			// ��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		// ����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//
	GPIO_Init(GPIOE, &GPIO_InitStructure);						// ��ʼ��GPIO
#endif
#if KEY2_DEF
	// KEY0 ����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			 // ��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		 // ����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			 // ����
	GPIO_Init(GPIOE, &GPIO_InitStructure);						 // ��ʼ��GPIO
#endif
#if KEYUP_DEF
	// KEYUP ����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			 // ��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		 // ����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;		 //
	GPIO_Init(GPIOA, &GPIO_InitStructure);						 // ��ʼ��GPIO
#endif
}

// ����������
// ���ذ���ֵ
// mode:0,��֧��������;1,֧��������;
// 0��û���κΰ�������
// 1��KEY0����
// 2��KEY1����
// 3��KEY2����
// 4��WKUP���� WK_UP
// ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>WK_UP!!
u8 KEY_Scan(u8 mode)
{
	static u8 key_up = 1; // �������ɿ���־
	if (mode)
		key_up = 1; // ֧������
	if (key_up && (KEY1 == 0 || KEY2 == 0 || WK_UP == 1))
	{
		Delay_ms(10); // ȥ����
		key_up = 0;
		// if(KEY0==0)return 1;
		if (KEY1 == 0)
			return 3; // S4
		else if (KEY2 == 0)
			return 4; // S3
		else if (WK_UP == 1)
			return 2; // S2
	}
	else if (KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WK_UP == 0)
		key_up = 1;
	return 0; // �ް�������
}
