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
// ���
void vpp_test(void);

