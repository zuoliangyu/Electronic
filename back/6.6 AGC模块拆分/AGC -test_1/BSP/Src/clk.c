#include "clk.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

ErrorStatus Sysclk_Config(void)
{
	ErrorStatus state = SUCCESS;
	uint32_t pll_M;
	uint32_t pll_N;
	uint32_t pll_P;
	uint32_t pll_Q;

	// 配置过程参考STM32f407时钟树，使用外部始终倍频
	RCC_DeInit(); // rcc reset
	// 开启HSE时钟
	RCC_HSEConfig(RCC_HSE_ON); // 23、24pin. 8MHz
	// 等待HSE稳定
	while (RCC_WaitForHSEStartUp() != SUCCESS)
		;

	pll_M = 8;	 // 8 div  , vco=8/8=1MHz
	pll_N = 144; //
	pll_P = 2;
	pll_Q = 3; // 这个系数用来配置SD/USB等功能
	// 当需要USB等功能时，注意pll_Q的值
	RCC_PLLConfig(RCC_PLLSource_HSE, pll_M, pll_N, pll_P, pll_Q);
	RCC_PLLCmd(ENABLE);

	// 至此，PLL时钟配置完毕
	// 接下来配置系统时钟
	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE); // 使用外部晶振8M作为系统始终源
	// RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK );//使用PLL作为系统始终源
	RCC_ClockSecuritySystemCmd(ENABLE);

	// AHB prescaler
	RCC_HCLKConfig(RCC_SYSCLK_Div1);
	// AHB1 clock config
	RCC_PCLK1Config(RCC_HCLK_Div4); // 42Mhz
	// AHB2 clock config
	RCC_PCLK2Config(RCC_HCLK_Div2); // 84MHz
	/* Enable Clock Security System(CSS): this will generate an NMI exception
				when HSE clock fails *****************************************************/

	return state;
}

void Clk_Output(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIOC Peripheral clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	/* GPIOC Peripheral clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	// MCO2
	/* Configure PC9 output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	RCC_MCO1Config(RCC_MCO1Source_PLLCLK, RCC_MCO1Div_4); // 168/4
	RCC_MCO2Config(RCC_MCO2Source_PLLCLK, RCC_MCO2Div_2); // 168/2
}
