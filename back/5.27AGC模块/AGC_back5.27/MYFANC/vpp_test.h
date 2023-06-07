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
// 测幅
void vpp_test(void);

