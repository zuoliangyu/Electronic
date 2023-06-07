#include "AD9959_DDS.h"
#include "delay.h"
#include "delay1.h"
#include "sweep.h"

float fre=100;


void sweep_fre(void)
{
	
	float Channel=3,fre=100;///通道选择
//	float Fout;///频率
	float amp=0.5;////初相位
	float V=17;
	float Pout;////幅度
	Pout=0.5253*V+2.1597;
	/*while(fre<1000)//100-1k
	{
		AD9959_Single_Output(Channel,fre,amp,Pout);
		 Delay_us(100000);
		fre=fre+100;
	}
	while(fre<10000)///1k-10k
	{
		AD9959_Single_Output(Channel,fre,amp,Pout);
			 Delay_us(100000);
		fre=fre+1000;
	}
	while(fre<100000)//10k-100k
	{
		AD9959_Single_Output(Channel,fre,amp,Pout);
			 Delay_us(100000);
		fre=fre+10000;
	}
	while(fre<1000000)//100k-1M
	{
		AD9959_Single_Output(Channel,fre,amp,Pout);
			 Delay_us(100000);
		fre=fre+100000;
	}*/
}

