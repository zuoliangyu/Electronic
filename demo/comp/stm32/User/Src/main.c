#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "cepin.h"
#include "cefu.h"
#include "change.h"
#include "frece.h"
#include "clk.h"
#include "led.h"
#include "delay.h"
#include "adc.h"
#include "key.h"
#include "i2s3.h"
#include "w25qxx.h"
#include "exti.h"
#include "iwdg.h"
#include "wwdg.h"
#include "24Cxx.h"
#include <string.h>
#include "fsmc.h"
#include "malloc.h"
#include "debug.h"
#include "usart0.h"
#include "use_led.h"
#include "square.h"
#include "sweep.h"
#include "use_led.h"

#define X	PGout(6)

#define SIZE sizeof(TEXT_Buffer)	 
#define p  ((u32)(0x68000000)) //FSMC--BANK1--SRAM3���׵�ַ

extern float voltage_amp1,voltage_amp2; 



int  main(void)
{
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����ϵͳ�ж����ȼ�����2
	USART2_Config(115200);
	uart_init(9600);	//���ڳ�ʼ��������Ϊ9600
	Delay_Config(168);	//HSE 8M
	FSMC_SRAM_Init();
	AD9959_Init();
  //int i;
	while(1)
	{
	LED_Config();////LED�Ƴ�ʼ��//
	change_Config();//��ʼ������
  //function();
	//AD9959_Single_Output(3,1000,1000,16);
	//AD9959_Single_Output(1,1000,0.000,1000);
	//AD9959_Single_Output(0,1000,0.000,1000);
	//AD9959_Single_Output(2,1000,0.000,1000);
	frequency();
	vpp_test();
	//sweep_fre();
	function();//
	HMI_Display_TxtFloat("t14.txt",voltage_amp1);
	if(!(strcmp(USART_RX_BUF,"1"))) 
			{
					LED0=1;		
			}
	vpp_test();
	//frecey();//Ƶ���ȶ�
	//Um_text();
	//cef_wd();//�������
	//u_vpp_test();///������������
	}
}

