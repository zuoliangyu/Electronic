#ifndef _BEEP_H_
#define _BEEP_H_

#include "stm32f4xx.h"

#define BEEP_Def	0


#define BEEP	PFout(8)


//STM32f407����û��BEEPӲ����Դ��������ҪIOģ��
void Beep_Config(void);
void Beep_Num(uint32_t times);

#endif
