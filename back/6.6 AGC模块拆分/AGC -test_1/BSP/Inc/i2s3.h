#ifndef _I2S3_H_
#define _I2S3_H_

#include "stm32f4xx.h"

void My_I2S3_Init(void);
void I2S3_Init(u16 I2S_Standard,u16 I2S_Mode,u16 I2S_Clock_Polarity,u16 I2S_DataFormat);
u8 I2S3_SampleRate_Set(u32 samplerate);
void I2S3_TX_DMA_Init(u8 * buf0, u8 *buf1, u16 num);
void I2S3_Play_Start(void);
void I2S3_Play_Stop(void);
#endif

