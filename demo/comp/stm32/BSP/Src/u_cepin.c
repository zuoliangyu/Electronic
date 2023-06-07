#include "stm32f4xx.h"
#include "cepin.h"
#include "stm32f4xx_conf.h"
#include "delay.h"

////////////////��Ƶ����//////////////////
u32 count_fx,count_base;             //�����ź������ؼ���ֵ����׼ʱ�������ؼ���ֵ
u32 tmp_low,tmp_high;          //�ߵ���ֵ
float u_fre_results;                   //�źŵ�Ƶ��ֵ


 //FSMC--BANK1--SRAM3���׵�ַ

////////////////��Ƶ����//////////////////
//��Ƶ��������

//��Ƶ
float  frequency(void)
{
	
	///////////////�����ź�////////////////
	//u32 *p=0x68000000;
  *(vu16*)(p+0x02)=0x0000;	//0_0000	���������㣬ʹ�ܹر�
	Delay_us(10);
	*(vu16*)(p+0x02)=0x0001;	//0_0001  ������������ ʹ�ܹر�
	Delay_us(10);
	*(vu16*)(p+0x02)=0x0003;	//0_0011  ������������ ʹ�ܴ򿪣���ʼ����������ʱ���1s
	Delay_us(100000);
	*(vu16*)(p+0x02)=0x0001;	//0_0001	������������  ʹ�ܹرա�
	
	/////////////��ȡ����///////////
	//�����źż���ֵ
	tmp_high=*(vu16*)(p+0x04);	//��16	100
	Delay_us(1000);
	tmp_low=*(vu16*)(p+0x06);	//��16	110
	Delay_us(1000);
	count_fx = tmp_low + (tmp_high<<16);
	Delay_us(1000);
	//��׼ʱ�Ӽ���ֵ
	tmp_high=*(vu16*)(p+0x08);	//��16	1000
	Delay_us(1000);
	tmp_low=*(vu16*)(p+0x0a);	//��16	1010
	Delay_us(1000);
  count_base = tmp_low + (tmp_high<<16);
	Delay_us(100);
	
	//����Ƶ��
	fre_results = 150000000.0 / count_base * count_fx;
	
  return u_fre_results;
}


