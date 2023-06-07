#ifndef _ADC_H_
#define _ADC_H_

#include "sys.h" 
#include "stm32f4xx_adc.h"


void Adc_Init(void); 				//ADC通道初始化
u16  Get_Adc(u8 ch); 				//获得某个通道值 
u16 Get_Adc_Average(u8 ch,u8 times);//得到某个通道给定次数采样的平均值  


#endif


