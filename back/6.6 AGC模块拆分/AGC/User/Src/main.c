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
// #define p  ((u32)(0x68000000)) //FSMC--BANK1--SRAM3的首地址

////////////////测频变量//////////////////
u32 count_fx, count_base; // 待测信号上升沿计数值、基准时钟上升沿计数值
u32 tmp_low, tmp_high;		// 高低数值
float fre_results;				// 信号的频率值

#define fifo_size 1024
#define p ((u32)(0x68000000)) // FSMC--BANK1--SRAM3的首地址

////////////////测幅变量//////////////////
float voltage_amp1, voltage_amp2; // 信号的幅值
u16 vol_maxnum1, vol_minnum1;			// 1024个ad采样数据的最大最小值；
u16 vol_maxnum2, vol_minnum2;
u16 fifo_data1[fifo_size]; // 1024个ad1采样数据
u16 fifo_data2[fifo_size]; // 1024个ad2采样数据
u32 M;										 // 频率字
u32 fs;										 // 待测信号频率
u16 adcx;
float AD_AD_temp; // 直流

float voltage_apm_AGC;
////////////////测频函数//////////////////
float frequency(void); // 测频函数定义

////////////////测幅函数//////////////////
void vpp_test(void); // 测幅函数定义
void trans_dds_consign(void);
void vpp_deal(void);
u16 find_min1(u16 *q); // 最小值函数
u16 find_max1(u16 *q); // 最大值函数
u16 find_min2(u16 *q); // 最小值函数
u16 find_max2(u16 *q); // 最大值函数
void vpp_test_AGC();	 /// AGC测量

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
		frequency();
		vpp_test();
		adcx = Get_Adc_Average(ADC_Channel_5, 20); // 获取通道5的转换值，获取1次后直接输出，可以更改取平均，如2的话就是2次取平均输出
		AD_AD_temp = (float)adcx * (3.3 / 4096);	// 获取计算后的带小数的实际电压值，比如3.1111
																							//*(vu16*)(p+0x02)=0x0001;
																							// d=*(vu16*)(p+0x14);
																							// d=d+1;
																							// d=0;
																							// LED_Config(d);
																							//*(vu8*)(Bank1_SRAM3_ADDR+WriteAddr)=*pBuffer;
		vpp_test_AGC();
	}
}

// 测频
float frequency(void)
{

	///////////////控制信号////////////////
	// u32 *p=0x68000000;
	*(vu16 *)(p + 0x02) = 0x0000; // 0_0000	计数器清零，使能关闭
	Delay_us(10);
	*(vu16 *)(p + 0x02) = 0x0001; // 0_0001  计数器不清零 使能关闭
	Delay_us(10);
	*(vu16 *)(p + 0x02) = 0x0003; // 0_0011  计数器不清零 使能打开，开始计数，计数时间给1s
	Delay_us(100000);
	*(vu16 *)(p + 0x02) = 0x0001; // 0_0001	计数器不清零  使能关闭。

	/////////////获取数据///////////
	// 待测信号计数值
	tmp_high = *(vu16 *)(p + 0x04); // 高16	100
	Delay_us(1000);
	tmp_low = *(vu16 *)(p + 0x06); // 低16	110
	Delay_us(1000);
	count_fx = tmp_low + (tmp_high << 16);
	Delay_us(1000);
	// 基准时钟计数值
	tmp_high = *(vu16 *)(p + 0x08); // 高16	1000
	Delay_us(1000);
	tmp_low = *(vu16 *)(p + 0x0a); // 低16	1010
	Delay_us(1000);
	count_base = tmp_low + (tmp_high << 16);
	Delay_us(1000);

	// 计算频率
	fre_results = 150000000.0 / count_base * count_fx;

	return fre_results;
}
// 使用AGC进行测量
void vpp_test_AGC(void)
{
	voltage_apm_AGC=0;
	// voltage_apm_AGC = 2 * pow(10, -6) * exp(9.0902 * AD_AD_temp);
	//  进行校对
	//第一个范围，此时v_in<1.2
	if (AD_AD_temp > 1 && AD_AD_temp < 1.485)
	{
		voltage_apm_AGC = 0.0000016489 * exp(9.0893190823 * AD_AD_temp);
	}
	//第二个范围，此时1.2<v_in<3
	else if(AD_AD_temp<1.585){
		voltage_apm_AGC=19.13*AD_AD_temp - 27.307;
	}
	//第三个范围，此时3<v_in<10
	else{
		voltage_apm_AGC=0.0000036727*exp(8.6090172150 *AD_AD_temp);
	}
}

// 测幅
void vpp_test(void)
{
	fs = 1000 * 1024.0 / (f32)(1024 + 1); // 计算采样频率
	M = 4294967296.0 * fs / 150000000.0;	// 计算频率字
	trans_dds_consign();									// 发送控制信号给FPGA
	vpp_deal();														// 计算峰峰值
}

// AD控制
void trans_dds_consign(void)
{
	int i, j;

	// M为32位数据，因此分两次（高16位和低16位）发送

	// 1.发送M的高16位	6=110	1100
	*(vu16 *)(p + 0x0c) = (u32)M >> 16;
	Delay_us(1000);

	// 2.发送M的低16位	7=111	1110
	*(vu16 *)(p + 0x0e) = (u32)M & 0x0000ffff;
	;
	Delay_us(1000);

	// 3.使能，输出fs采样信号
	*(vu16 *)(p + 0x2) = 0x0011;
	Delay_us(1000);

	// 等待采样完成，即fifo写满

	// 4.FIFO写使能
	*(vu16 *)(p + 0x2) = 0x0015; // fifo写使能开启，同时要开启AD转换功能
	while (*(vu16 *)(p + 0x12) != 0x0001)
		; // 等待fifo1写满
	while (*(vu16 *)(p + 0x16) != 0x0001)
		; // 等待fifo2写满
	*(vu16 *)(p + 0x02) = 0x0011;
	Delay_us(1000);

	// 5.FIFO1读使能
	*(vu16 *)(p + 0x02) = 0x0019;		// fifo1读使能开启
	for (i = 0; i < fifo_size; i++) // 读取fifo1中的数据
	{
		fifo_data1[i] = *(vu16 *)(p + 0x10);
	}
	*(vu16 *)(p + 0x02) = 0x0011;

	// 6.FIFO2读使能
	*(vu16 *)(p + 0x02) = 0x0039;		// fifo2读使能开启   //11_1001
	for (j = 0; j < fifo_size; j++) // 读取fifo2中的数据
	{
		// a=1010 1 0100=14
		fifo_data2[j] = *(vu16 *)(p + 0x14);
	}
}

// 对采样数据进行处理
void vpp_deal(void)
{
	// 1.获取高电平的最大值及其序号、低电平的最小值及其序号
	vol_maxnum1 = find_max1(fifo_data1); // FIFO1最大值
	vol_minnum1 = find_min1(fifo_data1); // FIFO1最小值
	vol_maxnum2 = find_max2(fifo_data2); // FIFO2最大值
	vol_minnum2 = find_min2(fifo_data2); // FIFO2最小值

	// 2.计算幅值(基准电压2V，根据实际调整)
	voltage_amp1 = (2.0 * (vol_maxnum1 - vol_minnum1)) / 16384; // AD1峰峰值
	voltage_amp2 = (5.0 * (vol_maxnum2 - vol_minnum2)) / 16384; // AD2峰峰值
	// 校验
	//voltage_amp2 = -0.108 * pow(voltage_amp2, 3) + 0.1952 * pow(voltage_amp2, 2) + 1.0828 * voltage_amp2 + 0.0033;
	// voltage_amp2 = -0.108 * voltage_amp2 * voltage_amp2 * voltage_amp2 + 0.1952 * voltage_amp2 * voltage_amp2 + 1.0828 * voltage_amp2 + 0.0033;
	Delay_us(1000);
}

// 找到fifo1最大值
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

// 找到fifo1最小值
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

// 找到fifo2最大值
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

// 找到fifo2最小值
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
