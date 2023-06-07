#include "sys.h"  
#include "misc.h"
#include "stdio.h"
#include "stm32f4xx_rcc.h"
#include "core_cm4.h"


//THUMB指令不支持汇编内联
//采用如下方法实现执行汇编指令WFI  
__asm void WFI_SET(void)
{
	WFI;		  
}
//关闭所有中断(但是不包括fault和NMI中断)
__asm void INTX_DISABLE(void)
{
	CPSID   I
	BX      LR	  
}
//开启所有中断
__asm void INTX_ENABLE(void)
{
	CPSIE   I
	BX      LR  
}
//设置栈顶地址
//addr:栈顶地址
__asm void MSR_MSP(uint32_t addr) 
{
	MSR MSP, r0 			//set Main Stack value
	BX r14
}


void SysTick_Init(void)
{
	 if (SysTick_Config(SystemCoreClock / 1000))
	{ 
		/* Capture error */ 
		while (1);
	}
	
	
}


void PrintSysclkInfo(void)
{
	RCC_ClocksTypeDef	RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	
	printf("\r\n/*************Print SysClk Info******************/\r\n");
	/**
	- 0x00: HSI used as system clock
	- 0x04: HSE used as system clock
	- 0x08: PLL used as system clock
   */
   
	switch(RCC_GetSYSCLKSource())
	{
		case 0x00:
			printf("当前时钟源:HSI\r\n");
			break;
		case 0x04:
			printf("当前时钟源:HSE\r\n");
			break;
		case 0x08:
			printf("当前时钟源:PLL\r\n");
			break;
		default:
			printf("时钟源出错，进入死循环！\r\n");
			while(1);
	}
	
	
	printf("SYSCLK_Frequency:%ld Hz\r\n", RCC_Clocks.SYSCLK_Frequency);
	printf("HCLK_Frequency:%ld Hz\r\n", RCC_Clocks.HCLK_Frequency);
	printf("PCLK1_Frequency:%ld Hz\r\n", RCC_Clocks.PCLK1_Frequency);
	printf("PCLK1_Frequency:%ld Hz\r\n\r\n", RCC_Clocks.PCLK2_Frequency);
	
}












