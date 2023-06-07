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
// #include "vpp_test.h"

#define X PGout(6)
const u8 TEXT_Buffer[] = {"0123456789"};
#define SIZE sizeof(TEXT_Buffer)
// #define p  ((u32)(0x68000000)) //FSMC--BANK1--SRAM3���׵�ַ

////////////////��Ƶ����//////////////////
u32 count_fx, count_base; // �����ź������ؼ���ֵ����׼ʱ�������ؼ���ֵ
u32 tmp_low, tmp_high;		// �ߵ���ֵ
float fre_results;				// �źŵ�Ƶ��ֵ

#define fifo_size 1024
#define p ((u32)(0x68000000)) // FSMC--BANK1--SRAM3���׵�ַ

////////////////�������//////////////////
float voltage_amp1, voltage_amp2; // �źŵķ�ֵ
u16 vol_maxnum1, vol_minnum1;			// 1024��ad�������ݵ������Сֵ��
u16 vol_maxnum2, vol_minnum2;
u16 fifo_data1[fifo_size]; // 1024��ad1��������
u16 fifo_data2[fifo_size]; // 1024��ad2��������
u32 M;										 // Ƶ����
u32 fs;										 // �����ź�Ƶ��
u16 adcx;
float AD_AD_temp; // ֱ��

float voltage_apm_AGC;
////////////////��Ƶ����//////////////////
float frequency(void); // ��Ƶ��������

////////////////�������//////////////////
void vpp_test(void); // �����������
void trans_dds_consign(void);
void vpp_deal(void);
u16 find_min1(u16 *q); // ��Сֵ����
u16 find_max1(u16 *q); // ���ֵ����
u16 find_min2(u16 *q); // ��Сֵ����
u16 find_max2(u16 *q); // ���ֵ����
void vpp_test_AGC();	 /// AGC����

int main(void)
{

	/************variable define************/
	// u8 res=0;

	//	u16 b=10;
	/************sys define************/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // ����ϵͳ�ж����ȼ�����2
	USART2_Config(115200);
	Delay_Config(168); // HSE 8M
	Adc_Init();				 // ��ʼ��ADC
	//	Key_Config();

	FSMC_SRAM_Init();
	// u32 *p=0x68000000;

	while (1)
	{
		LED_Config();
		// fsmc_usart_com_test();//����ͨ��
		// FSMC_SRAM_WriteBuffer(buf,1,2);
		// FSMC_SRAM_ReadBuffer(a,2,2);
		frequency();
		vpp_test();
		adcx = Get_Adc_Average(ADC_Channel_5, 20); // ��ȡͨ��5��ת��ֵ����ȡ1�κ�ֱ����������Ը���ȡƽ������2�Ļ�����2��ȡƽ�����
		AD_AD_temp = (float)adcx * (3.3 / 4096);	// ��ȡ�����Ĵ�С����ʵ�ʵ�ѹֵ������3.1111
																							//*(vu16*)(p+0x02)=0x0001;
																							// d=*(vu16*)(p+0x14);
																							// d=d+1;
																							// d=0;
																							// LED_Config(d);
																							//*(vu8*)(Bank1_SRAM3_ADDR+WriteAddr)=*pBuffer;
		vpp_test_AGC();
	}
}

// ��Ƶ
float frequency(void)
{

	///////////////�����ź�////////////////
	// u32 *p=0x68000000;
	*(vu16 *)(p + 0x02) = 0x0000; // 0_0000	���������㣬ʹ�ܹر�
	Delay_us(10);
	*(vu16 *)(p + 0x02) = 0x0001; // 0_0001  ������������ ʹ�ܹر�
	Delay_us(10);
	*(vu16 *)(p + 0x02) = 0x0003; // 0_0011  ������������ ʹ�ܴ򿪣���ʼ����������ʱ���1s
	Delay_us(100000);
	*(vu16 *)(p + 0x02) = 0x0001; // 0_0001	������������  ʹ�ܹرա�

	/////////////��ȡ����///////////
	// �����źż���ֵ
	tmp_high = *(vu16 *)(p + 0x04); // ��16	100
	Delay_us(1000);
	tmp_low = *(vu16 *)(p + 0x06); // ��16	110
	Delay_us(1000);
	count_fx = tmp_low + (tmp_high << 16);
	Delay_us(1000);
	// ��׼ʱ�Ӽ���ֵ
	tmp_high = *(vu16 *)(p + 0x08); // ��16	1000
	Delay_us(1000);
	tmp_low = *(vu16 *)(p + 0x0a); // ��16	1010
	Delay_us(1000);
	count_base = tmp_low + (tmp_high << 16);
	Delay_us(1000);

	// ����Ƶ��
	fre_results = 150000000.0 / count_base * count_fx;

	return fre_results;
}
// ʹ��AGC���в���
void vpp_test_AGC(void)
{
	voltage_apm_AGC=0;
	// voltage_apm_AGC = 2 * pow(10, -6) * exp(9.0902 * AD_AD_temp);
	//  ����У��
	//��һ����Χ����ʱv_in<1.2
	if (AD_AD_temp > 1 && AD_AD_temp < 1.485)
	{
		voltage_apm_AGC = 0.0000016489 * exp(9.0893190823 * AD_AD_temp);
	}
	//�ڶ�����Χ����ʱ1.2<v_in<3
	else if(AD_AD_temp<1.585){
		voltage_apm_AGC=19.13*AD_AD_temp - 27.307;
	}
	//��������Χ����ʱ3<v_in<10
	else{
		voltage_apm_AGC=0.0000036727*exp(8.6090172150 *AD_AD_temp);
	}
}

// ���
void vpp_test(void)
{
	fs = 1000 * 1024.0 / (f32)(1024 + 1); // �������Ƶ��
	M = 4294967296.0 * fs / 150000000.0;	// ����Ƶ����
	trans_dds_consign();									// ���Ϳ����źŸ�FPGA
	vpp_deal();														// ������ֵ
}

// AD����
void trans_dds_consign(void)
{
	int i, j;

	// MΪ32λ���ݣ���˷����Σ���16λ�͵�16λ������

	// 1.����M�ĸ�16λ	6=110	1100
	*(vu16 *)(p + 0x0c) = (u32)M >> 16;
	Delay_us(1000);

	// 2.����M�ĵ�16λ	7=111	1110
	*(vu16 *)(p + 0x0e) = (u32)M & 0x0000ffff;
	;
	Delay_us(1000);

	// 3.ʹ�ܣ����fs�����ź�
	*(vu16 *)(p + 0x2) = 0x0011;
	Delay_us(1000);

	// �ȴ�������ɣ���fifoд��

	// 4.FIFOдʹ��
	*(vu16 *)(p + 0x2) = 0x0015; // fifoдʹ�ܿ�����ͬʱҪ����ADת������
	while (*(vu16 *)(p + 0x12) != 0x0001)
		; // �ȴ�fifo1д��
	while (*(vu16 *)(p + 0x16) != 0x0001)
		; // �ȴ�fifo2д��
	*(vu16 *)(p + 0x02) = 0x0011;
	Delay_us(1000);

	// 5.FIFO1��ʹ��
	*(vu16 *)(p + 0x02) = 0x0019;		// fifo1��ʹ�ܿ���
	for (i = 0; i < fifo_size; i++) // ��ȡfifo1�е�����
	{
		fifo_data1[i] = *(vu16 *)(p + 0x10);
	}
	*(vu16 *)(p + 0x02) = 0x0011;

	// 6.FIFO2��ʹ��
	*(vu16 *)(p + 0x02) = 0x0039;		// fifo2��ʹ�ܿ���   //11_1001
	for (j = 0; j < fifo_size; j++) // ��ȡfifo2�е�����
	{
		// a=1010 1 0100=14
		fifo_data2[j] = *(vu16 *)(p + 0x14);
	}
}

// �Բ������ݽ��д���
void vpp_deal(void)
{
	// 1.��ȡ�ߵ�ƽ�����ֵ������š��͵�ƽ����Сֵ�������
	vol_maxnum1 = find_max1(fifo_data1); // FIFO1���ֵ
	vol_minnum1 = find_min1(fifo_data1); // FIFO1��Сֵ
	vol_maxnum2 = find_max2(fifo_data2); // FIFO2���ֵ
	vol_minnum2 = find_min2(fifo_data2); // FIFO2��Сֵ

	// 2.�����ֵ(��׼��ѹ2V������ʵ�ʵ���)
	voltage_amp1 = (2.0 * (vol_maxnum1 - vol_minnum1)) / 16384; // AD1���ֵ
	voltage_amp2 = (5.0 * (vol_maxnum2 - vol_minnum2)) / 16384; // AD2���ֵ
	// У��
	//voltage_amp2 = -0.108 * pow(voltage_amp2, 3) + 0.1952 * pow(voltage_amp2, 2) + 1.0828 * voltage_amp2 + 0.0033;
	// voltage_amp2 = -0.108 * voltage_amp2 * voltage_amp2 * voltage_amp2 + 0.1952 * voltage_amp2 * voltage_amp2 + 1.0828 * voltage_amp2 + 0.0033;
	Delay_us(1000);
}

// �ҵ�fifo1���ֵ
u16 find_max1(u16 *q)
{
	u16 x;
	u16 max = *q;

	for (x = 0; x < fifo_size; x++)
	{
		if (*q > max)
		{
			max = *q;
		}
		q++;
	}
	return max;
}

// �ҵ�fifo1��Сֵ
u16 find_min1(u16 *q)
{
	u16 x;
	u16 min = *q;
	for (x = 0; x < fifo_size; x++)
	{
		if (*q < min)
		{
			min = *q;
		}
		q++;
	}
	return min;
}

// �ҵ�fifo2���ֵ
u16 find_max2(u16 *q)
{
	u16 x;
	u16 max = *q;

	for (x = 0; x < fifo_size; x++)
	{
		if (*q > max)
		{
			max = *q;
		}
		q++;
	}
	return max;
}

// �ҵ�fifo2��Сֵ
u16 find_min2(u16 *q)
{
	u16 x;
	u16 min = *q;
	for (x = 0; x < fifo_size; x++)
	{
		if (*q < min)
		{
			min = *q;
		}
		q++;
	}
	return min;
}
