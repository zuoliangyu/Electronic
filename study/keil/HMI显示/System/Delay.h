#ifndef __DELAY_H
#define __DELAY_H 			   
#include <sys.h>	  

void Delay_Config(uint8_t SYSCLK);
void Delay_ms(u16 nms);
void Delay_us(uint32_t nus);
void Delay(uint32_t time);

#endif





























