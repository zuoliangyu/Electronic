#include "sys.h"  
#include "misc.h"
#include "stdio.h"
#include "stm32f4xx_rcc.h"
#include "core_cm4.h"


//THUMBָ�֧�ֻ������
//�������·���ʵ��ִ�л��ָ��WFI  
__asm void WFI_SET(void)
{
	WFI;		  
}
//�ر������ж�(���ǲ�����fault��NMI�ж�)
__asm void INTX_DISABLE(void)
{
	CPSID   I
	BX      LR	  
}
//���������ж�
__asm void INTX_ENABLE(void)
{
	CPSIE   I
	BX      LR  
}
//����ջ����ַ
//addr:ջ����ַ
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
			printf("��ǰʱ��Դ:HSI\r\n");
			break;
		case 0x04:
			printf("��ǰʱ��Դ:HSE\r\n");
			break;
		case 0x08:
			printf("��ǰʱ��Դ:PLL\r\n");
			break;
		default:
			printf("ʱ��Դ����������ѭ����\r\n");
			while(1);
	}
	
	
	printf("SYSCLK_Frequency:%ld Hz\r\n", RCC_Clocks.SYSCLK_Frequency);
	printf("HCLK_Frequency:%ld Hz\r\n", RCC_Clocks.HCLK_Frequency);
	printf("PCLK1_Frequency:%ld Hz\r\n", RCC_Clocks.PCLK1_Frequency);
	printf("PCLK1_Frequency:%ld Hz\r\n\r\n", RCC_Clocks.PCLK2_Frequency);
	
}












