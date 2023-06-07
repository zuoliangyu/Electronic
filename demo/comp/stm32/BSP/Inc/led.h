#ifndef _LED_H_
#define _LED_H_

#include "stm32f4xx.h"

//0-NOT use, 1-ues
#define USE_bIT_BAND	1

#if(USE_bIT_BAND == 0)
//�궨���е�\��Ϊ���ӷ�ǰ������white space
#define LED0(x)	if(x)\
					GPIO_ResetBits(GPIOF, GPIO_Pin_9);\
				else\
					GPIO_SetBits(GPIOF, GPIO_Pin_9)
#define LED1(x)	if(x)\
					GPIO_ResetBits(GPIOF, GPIO_Pin_10);\
				else\
					GPIO_SetBits(GPIOF, GPIO_Pin_10)
#elif(USE_bIT_BAND == 1)
//#pragma message("use bit-banding")
#include "sys.h"
#define LED0	PFout(9)
#define LED1	PFout(10)

#endif

void LED_Config(void);

#endif
