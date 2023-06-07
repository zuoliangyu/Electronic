/* Includes ------------------------------------------------------------------*/
#include "timer.h"

void TIM2_Cap_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
  GPIO_Init(GPIOA,&GPIO_InitStructure);
  GPIO_SetBits(GPIOA,GPIO_Pin_0);
  
  TIM_TimeBaseStructure.TIM_Period=0xFFFF;
  TIM_TimeBaseStructure.TIM_Prescaler=0;
  TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
	TIM_ITRxExternalClockConfig(TIM2,TIM_TS_ETRF);
	TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0);
	TIM_SetCounter(TIM2,0);
	TIM_Cmd(TIM2,ENABLE);
}


void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	TIM_TimeBaseStructure.TIM_Period=arr;
	TIM_TimeBaseStructure.TIM_Prescaler=psc;
	TIM_TimeBaseStructure.TIM_ClockDivision=0;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);
	TIM_ITConfig(
	TIM3,
	TIM_IT_Update,
	ENABLE
	);
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	TIM_Cmd(TIM3,ENABLE);
	
	
}

