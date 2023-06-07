#ifndef _FSMC_H_
#define _FSMC_H_
#include "sys.h"

//V1.1 20140729
//1,�޸�FSMC_SRAM_Init����,���渴λ���ʼ������SRAM����.
////////////////////////////////////////////////////////////////////////////////// 	 

#define READ_FPGA	PAin(10)

void FSMC_SRAM_Init(void);
void FSMC_SRAM_WriteBuffer(u8* pBuffer,u32 WriteAddr,u32 NumHalfwordToWrite);
void FSMC_SRAM_ReadBuffer(u8* pBuffer,u32 ReadAddr,u32 NumHalfwordToRead);


void fsmc_sram_test_write(u32 addr,u8 data);
u8 fsmc_sram_test_read(u32 addr);
void fsmc_fpga_test(void);
void fsmc_usart_com_test(void);//����ͨ��
void fsmc_usart_read(void);
void fsmc_wav_datatransfer_test(void);//wav test

#endif



