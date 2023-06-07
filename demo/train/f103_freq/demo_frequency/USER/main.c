#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"


int CNT,cnt,flag,TIM2CH1_CAPTURE_VAL,overflow;
void data_output(void);
void data_output(void);
void TIM3_IRQHandler(void);
void TIM2_IRQHandler(void);
void time(int t)
{
	int i;
	while(t--)
	{
		for(i=0;i<120;i++);
	}
}
int main(void)
{		
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	 //串口初始化为9600
  delay_init();	    	 //延时函数初始化
	//定时器初始化
	TIM2_Cap_Init();
  LED_Init();
}



void data_output()
{
	if(CNT<10000)
		printf("%d \r\n",CNT);
	else
	{
		cnt=CNT*(1+0.00019);
		printf("%d \r\n",cnt);
	}
	TIM_SetCounter(TIM2,0);
	TIM_SetCounter(TIM3,0);
	CNT=0;
	flag=0;
	TIM_Cmd(TIM2,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
	{
		TIM2CH1_CAPTURE_VAL=TIM_GetCounter(TIM2);
		TIM_Cmd(TIM2,DISABLE);
		TIM_Cmd(TIM3,DISABLE);
		TIM_SetCounter(TIM2,0);
		flag++;
		
		CNT+=TIM2CH1_CAPTURE_VAL+overflow*65535;
		overflow=0;
		
		if(flag<200)
		{
			TIM_Cmd(TIM2,ENABLE);
			TIM_Cmd(TIM3,ENABLE);
		}
    else
      data_output();
    TIM_ClearITPendingBit(TIM3,TIM_IT_CC1|TIM_IT_Update);
   }
}
			
			
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)
		overflow++;
	TIM_ClearITPendingBit(TIM2,TIM_IT_CC1|TIM_IT_Update);
}


		
	
	
	

