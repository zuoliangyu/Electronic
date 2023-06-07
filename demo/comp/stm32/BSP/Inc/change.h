#ifndef _CHANGE_H_
#define _CHANGE_H_

#include "stm32f4xx.h"
#include "cefu.h"

//0-NOT use, 1-ues
#define USE_bIT_BAND	1

#if(USE_bIT_BAND == 0)
//宏定义中的\作为连接符前不能有white space
#define CHANGE0(x)	if(x)\
					GPIO_ResetBits(GPIOA, GPIO_Pin_8);\
				else\
					GPIO_SetBits(GPIOA, GPIO_Pin_8)
#define CHANGE1(x)	if(x)\
					GPIO_ResetBits(GPIOC, GPIO_Pin_9);\
				else\
					GPIO_SetBits(GPIOC, GPIO_Pin_9)
#define CHANGE2(x)	if(x)\
					GPIO_ResetBits(GPIOC, GPIO_Pin_8);\
				else\
					GPIO_SetBits(GPIOC, GPIO_Pin_8)
#define CHANGE3(x)	if(x)\
					GPIO_ResetBits(GPIOC, GPIO_Pin_7);\
				else\
					GPIO_SetBits(GPIOC, GPIO_Pin_7)
#define CHANGE4(x)	if(x)\
					GPIO_ResetBits(GPIOG, GPIO_Pin_6);\
				else\
					GPIO_SetBits(GPIOG, GPIO_Pin_6)
#elif(USE_bIT_BAND == 1)
//#pragma message("use bit-banding")
#include "sys.h"
#define CHANGE0	PAout(8)
#define CHANGE1	PCout(9)
#define CHANGE2	PCout(8)
#define CHANGE3	PCout(7)
#define CHANGE4	PGout(6)
#endif

void change_Config(void);
void change_switch(void );
void Initgear(void);
void cef_wd(void );
float vpp_v(void);
void autoset(void);
//int int_pow(int x,int y);


#endif
