#ifndef _ADC_H_
#define _ADC_H_

#include "sys.h" 
#include "stm32f4xx_adc.h"


void Adc_Init(void); 				//ADCͨ����ʼ��
u16  Get_Adc(u8 ch); 				//���ĳ��ͨ��ֵ 
u16 Get_Adc_Average(u8 ch,u8 times);//�õ�ĳ��ͨ����������������ƽ��ֵ  


#endif


