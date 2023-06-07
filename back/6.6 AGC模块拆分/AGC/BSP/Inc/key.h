#ifndef _KEY_H_
#define _KEY_H_
#include "stm32f4xx.h"

#define KEY0_DEF	1
#define KEY1_DEF	1
#define KEY2_DEF	1
#define KEYUP_DEF	1


/*下面的方式是通过直接操作库函数方式读取IO*/
#define KEY0 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) //PE4
#define KEY1 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)	//PE3 
#define KEY2 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) //PE2
#define WK_UP 		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)	//PA0

#define S2	WK_UP
#define S3	KEY2
#define S4	KEY1


#define KEY0_PRES 	1
#define KEY1_PRES		2
#define KEY2_PRES		3
#define WKUP_PRES   4


void Key_Config(void);
void Key_Scan(void);
u8 KEY_Scan(u8 mode);
#endif
