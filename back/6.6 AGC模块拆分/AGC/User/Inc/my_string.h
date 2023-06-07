#ifndef _my_string_h_
#define _my_string_h_

#include "my_def.h"
#include "stm32f4xx.h"

TestStatus BufferCmp(const uint8_t* pBuffer1,
											const uint8_t* pBuffer2,
												uint16_t bufferLen);
u8* GetFileName(const char * fpath);

#endif /*my_string.h*/
