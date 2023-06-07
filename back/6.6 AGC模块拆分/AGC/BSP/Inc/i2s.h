#ifndef _IIS_H_
#define _IIS_H_

#include "My_def.h"
#include "stm32f4xx.h"

void My_I2S_Init(void);

extern fnDef i2s_tx_callback;//iis tx callback function

void I2S2_Init(u16 i2s_standard,
	u16 i2s_mode,
	u16 i2s_clock_polartiy,
	u16 i2s_dataFormat
	);
u8 I2S2_SampleRate_Set(u32 samplerate);
void I2S2_TX_DMA_Init(u8 * buf0,
	u8 *buf1,
	u16 num
	);
void I2S_Play_Start(void);
void I2S_Play_Stop(void);



#endif
