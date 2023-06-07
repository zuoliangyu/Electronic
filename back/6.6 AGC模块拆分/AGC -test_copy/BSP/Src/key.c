#include "key.h"
#include "stm32f4xx_gpio.h"
#include "stdio.h"
#include "delay.h"

void Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); // 使能GPIOF时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); // 使能GPIOF时钟

#if KEY0_DEF
	// KEY0 共阴
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			 // 普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		 // 推挽
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			 //
	GPIO_Init(GPIOE, &GPIO_InitStructure);						 // 初始化GPIO
#endif

#if KEY1_DEF
	// KEY0 共阴
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			// 普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		// 推挽
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//
	GPIO_Init(GPIOE, &GPIO_InitStructure);						// 初始化GPIO
#endif
#if KEY2_DEF
	// KEY0 共阴
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			 // 普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		 // 推挽
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			 // 上拉
	GPIO_Init(GPIOE, &GPIO_InitStructure);						 // 初始化GPIO
#endif
#if KEYUP_DEF
	// KEYUP 共阴
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			 // 普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		 // 推挽
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;		 //
	GPIO_Init(GPIOA, &GPIO_InitStructure);						 // 初始化GPIO
#endif
}

// 按键处理函数
// 返回按键值
// mode:0,不支持连续按;1,支持连续按;
// 0，没有任何按键按下
// 1，KEY0按下
// 2，KEY1按下
// 3，KEY2按下
// 4，WKUP按下 WK_UP
// 注意此函数有响应优先级,KEY0>KEY1>KEY2>WK_UP!!
u8 KEY_Scan(u8 mode)
{
	static u8 key_up = 1; // 按键按松开标志
	if (mode)
		key_up = 1; // 支持连按
	if (key_up && (KEY1 == 0 || KEY2 == 0 || WK_UP == 1))
	{
		Delay_ms(10); // 去抖动
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
	return 0; // 无按键按下
}
