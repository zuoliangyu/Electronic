#ifndef _ERROR_H_
#define _ERROR_H_

#include "my_def.h"
#include "stm32f4xx.h"

typedef struct _ERROR_CODE_S
{
	u8 index;
	const unsigned char *pStr;
}ERROR_CODE_S;

ERROR_CODE_S (ERROR_CODE)[] = 
{
	{0x01, "Gt error"},
	{0x02, "font error"},
	{0x03, "fatfs error"},
	{0x04, "flash error"}
};


#endif
