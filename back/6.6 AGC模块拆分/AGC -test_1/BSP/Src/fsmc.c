#include "fsmc.h"
#include "malloc.h"
#include "usart2.h"
#include "delay.h"

// V1.1 20140729
// 1,修改FSMC_SRAM_Init函数,防止复位后初始化打乱SRAM数据.
//////////////////////////////////////////////////////////////////////////////////

// 使用NOR/SRAM的 Bank1.sector3,地址位HADDR[27,26]=10
// 对IS61LV25616/IS62WV25616,地址线范围为A0~A17
// 对IS61LV51216/IS62WV51216,地址线范围为A0~A18
#define Bank1_SRAM3_ADDR ((u32)(0x68000000))

// u32 testsram[25000] __attribute__((at(0X68000000)));//测试用数组
// 外部内存测试(最大支持1M字节内存测试)
void fsmc_sram_test(u16 x, u16 y)
{
	u32 i = 0;
	u8 temp = 0;
	u8 sval = 0; // 在地址0读到的数据
							 // LCD_ShowString(x,y,239,y+16,16,"Ex Memory Test:   0KB");
	// 每隔4K字节,写入一个数据,总共写入256个数据,刚好是1M字节
	for (i = 0; i < 1024 * 1024; i += 4096)
	{
		FSMC_SRAM_WriteBuffer(&temp, i, 1);
		temp++;
	}
	// 依次读出之前写入的数据,进行校验
	for (i = 0; i < 1024 * 1024; i += 4096)
	{
		FSMC_SRAM_ReadBuffer(&temp, i, 1);
		if (i == 0)
			sval = temp;
		else if (temp <= sval)
			break; // 后面读出的数据一定要比第一次读到的数据大.
		// LCD_ShowxNum(x+15*8,y,(u16)(temp-sval+1)*4,4,16,0);//显示内存容量
	}

	// mytest
}

// 初始化外部SRAM
void FSMC_SRAM_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	FSMC_NORSRAMInitTypeDef FSMC_NORSRAMInitStructure;
	FSMC_NORSRAMTimingInitTypeDef readWriteTiming;

	// init for FPGA-FSMC test
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE, ENABLE); // 使能GPIOA,GPIOE时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					 // TX
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			 // 普通输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // 100M
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			 // 上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;		 // RX
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 // 普通输入模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; // 下拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);				 // 初始化GPIOA0

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB |
														 RCC_AHB1Periph_GPIOD |
														 RCC_AHB1Periph_GPIOE |
														 RCC_AHB1Periph_GPIOF |
														 RCC_AHB1Periph_GPIOG,
												 ENABLE);											 // 使能PD,PE,PF,PG时钟
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE); // 使能FSMC时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				// PB15 推挽输出,控制背光
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			// 普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		// 推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// 上拉
	GPIO_Init(GPIOB, &GPIO_InitStructure);						// 初始化 //PB15 推挽输出,控制背光

	GPIO_InitStructure.GPIO_Pin = (3 << 0) | (3 << 4) | (0XFF << 8); // PD0,1,4,5,8~15 AF OUT
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;										 // 复用输出
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;									 // 推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							 // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;										 // 上拉
	GPIO_Init(GPIOD, &GPIO_InitStructure);													 // 初始化

	GPIO_InitStructure.GPIO_Pin = (3 << 0) | (0X1FF << 7); // PE0,1,7~15,AF OUT
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;					 // 复用输出
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;				 // 推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		 // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;					 // 上拉
	GPIO_Init(GPIOE, &GPIO_InitStructure);								 // 初始化

	GPIO_InitStructure.GPIO_Pin = (0X3F << 0) | (0XF << 12); // PF0~5,12~15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;						 // 复用输出
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;					 // 推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;			 // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						 // 上拉
	GPIO_Init(GPIOF, &GPIO_InitStructure);									 // 初始化

	GPIO_InitStructure.GPIO_Pin = (0X3F << 0) | GPIO_Pin_10; // PG0~5,10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;						 // 复用输出
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;					 // 推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;			 // 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						 // 上拉
	GPIO_Init(GPIOG, &GPIO_InitStructure);									 // 初始化

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FSMC); // PD0,AF12
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FSMC); // PD1,AF12
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource4, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource11, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FSMC); // PD15,AF12

	GPIO_PinAFConfig(GPIOE, GPIO_PinSource0, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource7, GPIO_AF_FSMC); // PE7,AF12
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource8, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource10, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource15, GPIO_AF_FSMC); // PE15,AF12

	GPIO_PinAFConfig(GPIOF, GPIO_PinSource0, GPIO_AF_FSMC);	 // PF0,AF12
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource1, GPIO_AF_FSMC);	 // PF1,AF12
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource2, GPIO_AF_FSMC);	 // PF2,AF12
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource3, GPIO_AF_FSMC);	 // PF3,AF12
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource4, GPIO_AF_FSMC);	 // PF4,AF12
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource5, GPIO_AF_FSMC);	 // PF5,AF12
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource12, GPIO_AF_FSMC); // PF12,AF12
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource13, GPIO_AF_FSMC); // PF13,AF12
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource14, GPIO_AF_FSMC); // PF14,AF12
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource15, GPIO_AF_FSMC); // PF15,AF12

	GPIO_PinAFConfig(GPIOG, GPIO_PinSource0, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOG, GPIO_PinSource1, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOG, GPIO_PinSource2, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOG, GPIO_PinSource3, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOG, GPIO_PinSource4, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOG, GPIO_PinSource5, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOG, GPIO_PinSource10, GPIO_AF_FSMC);

	readWriteTiming.FSMC_AddressSetupTime = 0x05; // 地址建立时间（ADDSET）为1个HCLK 1/36M=27ns
	readWriteTiming.FSMC_AddressHoldTime = 0x05;	// 地址保持时间（ADDHLD）模式A未用到
	readWriteTiming.FSMC_DataSetupTime = 0x08;		// 数据保持时间（DATAST）为9个HCLK 6*9=54ns
	readWriteTiming.FSMC_BusTurnAroundDuration = 0x00;
	readWriteTiming.FSMC_CLKDivision = 0x00;
	readWriteTiming.FSMC_DataLatency = 0x00;
	readWriteTiming.FSMC_AccessMode = FSMC_AccessMode_A; // 模式A

	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM3; //  这里我们使用NE3 ，也就对应BTCR[4],[5]。
	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
	FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;							 // FSMC_MemoryType_SRAM;  //SRAM
	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;		 // 存储器数据宽度为16bit
	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable; // FSMC_BurstAccessMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable; // 存储器写使能
	FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable; // 读写使用相同的时序
	FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &readWriteTiming;
	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &readWriteTiming; // 读写同样时序

	FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); // 初始化FSMC配置
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM3, ENABLE); // 使能BANK1区域3
}

// 在指定地址(WriteAddr+Bank1_SRAM3_ADDR)开始,连续写入n个字节.
// pBuffer:字节指针
// WriteAddr:要写入的地址
// n:要写入的字节数
void FSMC_SRAM_WriteBuffer(u8 *pBuffer, u32 WriteAddr, u32 n)
{
	for (; n != 0; n--)
	{
		*(vu8 *)(Bank1_SRAM3_ADDR + WriteAddr) = *pBuffer; // 数组指针的值写入fpga中定义地址的空间
		WriteAddr++;																			 // fpga里面定义的地址信号
		pBuffer++;																				 // 数组指针
	}
}

// 在指定地址((WriteAddr+Bank1_SRAM3_ADDR))开始,连续读出n个字节.
// pBuffer:字节指针
// ReadAddr:要读出的起始地址
// n:要写入的字节数
void FSMC_SRAM_ReadBuffer(u8 *pBuffer, u32 ReadAddr, u32 n)
{
	for (; n != 0; n--)
	{
		*pBuffer++ = *(vu8 *)(Bank1_SRAM3_ADDR + ReadAddr);
		ReadAddr++;
	}
}
////////////////////////////////////////////////////////////////////////////////////////
// 测试函数
// 在指定地址写入1个字节
// addr:地址(0~SRAM大小)
// data:要写入的数据
void fsmc_sram_test_write(u32 addr, u8 data)
{
	FSMC_SRAM_WriteBuffer(&data, addr, 1); // 写入1个字节
}
// 读取1个字节
// addr:要读取的地址(0~SRAM大小)
// 返回值:读取到的数据
u8 fsmc_sram_test_read(u32 addr)
{
	u8 data;
	FSMC_SRAM_ReadBuffer(&data, addr, 1);
	return data;
}

#include <string.h>
void fsmc_usart_com_test(void)
{
	u8 i = 0;
	u16 t16 = 0xAA55;
	u16 tmp;
	memset(USART_RX_BUF, 0, USART_REC_LEN);

	while (1)
	{

		if (USART_RX_STA && (USART_RX_STA < USART_REC_LEN))
		{
			// printf("cnt:%d\t", USART_RX_STA);
			Delay_ms(5);
			for (i = 0; i < USART_RX_STA; i += 2)
			{
				tmp = USART_RX_BUF[i] << 8 | USART_RX_BUF[i + 1];
				// printf("tmp:%x", tmp);
				*(vu16 *)((u32)(0x68000000) + t16 * 2) = tmp;
			}
			// printf("%c", t);
			// fsmc_sram_test_write(0xaa55*2, 0x55);
			// FSMC_SRAM_WriteBuffer(&t , 0xaa55*2, 1);

			//*( vu8*)((u32)(0x68000000)+0x1234*2)=t;//地址发送完以后状态会改变
			// fsmc_sram_test_write(0x1234*2, 0x55);
			USART_RX_STA = 0;
		}

		if (READ_FPGA)
		{
			tmp = *(vu16 *)((u32)(0x68000000) + 0x55AA * 2);
			printf("%c%c", tmp >> 8, tmp & 0x00ff);
		}
	}
}
