#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "clk.h"
#include "led.h"
#include "delay.h"
#include "adc.h"
#include "usart1.h"
#include "key.h"
#include "i2s3.h"
#include "w25qxx.h"
#include "exti.h"
#include "iwdg.h"
#include "wwdg.h"
#include "24Cxx.h"
#include "usart2.h"
#include <string.h>
#include "fsmc.h"
#include "malloc.h"
#include "debug.h"
#include "adc.h"
#include <math.h>
#include "vpp_test.h"
#include "frequency.h"
#define X PGout(6)
const u8 TEXT_Buffer[] = {"0123456789"};
#define SIZE sizeof(TEXT_Buffer)
int main(void)
{

	/************variable define************/
	// u8 res=0;

	//	u16 b=10;
	/************sys define************/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 设置系统中断优先级分组2
	USART2_Config(115200);
	Delay_Config(168); // HSE 8M
	Adc_Init();				 // 初始化ADC
	//	Key_Config();

	FSMC_SRAM_Init();
	// u32 *p=0x68000000;

	while (1)
	{
		LED_Config();
		// fsmc_usart_com_test();//串口通信
		// FSMC_SRAM_WriteBuffer(buf,1,2);
		// FSMC_SRAM_ReadBuffer(a,2,2);
		frequency();		// 测频
		vpp_test();			// 测幅AD
		vpp_test_AGC(); // 测幅AGC
										//*(vu16*)(p+0x02)=0x0001;
										// d=*(vu16*)(p+0x14);
										// d=d+1;
										// d=0;
										// LED_Config(d);
										//*(vu8*)(Bank1_SRAM3_ADDR+WriteAddr)=*pBuffer;
	}
}
