#ifndef _DEBUG_USART2_H_
#define _DEBUG_USART2_H_

#include <stdio.h>
#include "usart0.h"

void USART2_Config(uint32_t bound);
void USART2_SendStrings(const unsigned char * str, size_t	size);

#endif

