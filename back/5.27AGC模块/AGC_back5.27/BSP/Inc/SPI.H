#ifndef _SPI_H_
#define _SPI_H_

#pragma once

#include "stm32f4xx.h"
#include "stm32f4xx_spi.h"

void SPI1_Init(void);			 //初始化SPI1口
void SPI1_SetSpeed(uint8_t SpeedSet); //设置SPI1速度   
uint8_t SPI1_ReadWriteByte(uint8_t TxData);//SPI1总线读写一个字节


#endif

