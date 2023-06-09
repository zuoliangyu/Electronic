#include "usart_base.h"
#include "usart2.h"
#include "stm32f4xx_usart.h"
#include "sys.h"

/////////////////////////////////////////////////////////////////
// 加入以下代码,支持printf函数,而不需要选择use MicroLIB
#if USART == 2
#pragma import(__use_no_semihosting)
// 标准库需要的支持函数
struct __FILE
{
	int handle;
};

FILE __stdout;
// 定义_sys_exit()以避免使用半主机模式
void _sys_exit(int x)
{
	x = x;
}
// 重定义fputc函数
int fputc(int ch, FILE *f)
{
	while ((USART2->SR & 0X40) == 0)
		; // 循环发送,直到发送完毕
	USART2->DR = (uint8_t)ch;
	return ch;
}

// 串口1中断服务程序
// 注意,读取USARTx->SR能避免莫名其妙的错误
uint8_t USART_RX_BUF[USART_REC_LEN]; // 接收缓冲,最大USART_REC_LEN个字节.
// 接收状态
// bit15，	接收完成标志
// bit14，	接收到0x0d
// bit13~0，	接收到的有效字节数目
u16 USART_RX_STA = 0; // 接收状态标记
#endif

// 初始化IO 串口1
// bound:波特率
void USART2_Config(uint32_t bound)
{
	// GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	 // 使能GPIOA时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); // 使能USART2时钟

	// 串口2对应引脚复用映射
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); // GPIOA2复用为USART2
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2); // GPIOA10复用为USART2

	// USART1端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; // GPIOA2与GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;					 // 复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			 // 速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;				 // 推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;					 // 上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);								 // 初始化PA2，PA3

	// USART1 初始化设置
	USART_InitStructure.USART_BaudRate = bound;																			// 波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;											// 字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;													// 一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;															// 无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;									// 收发模式
	USART_Init(USART2, &USART_InitStructure);																				// 初始化串口1

	USART_Cmd(USART2, ENABLE); // 使能串口1

#if EN_USART2_RX
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // 开启相关中断

	// Usart1 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;					// 串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3; // 抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;				// 子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;						// IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);														// 根据指定的参数初始化VIC寄存器、

#endif
}

void USART2_IRQHandler(void)
{
	u8 res;
	if (USART2->SR & (1 << 5)) // 接收到数据
	{
		res = USART2->DR;
		if ((USART_RX_STA & 0x8000) == 0) // 接收未完成
		{
			if (USART_RX_STA & 0x4000) // 接收到了0x0d
			{
				if (res != 0x0a)
					USART_RX_STA = 0; // 接收错误,重新开始
				else
					USART_RX_STA |= 0x8000; // 接收完成了
			}
			else // 还没收到0X0D
			{
				if (res == 0x0d)
					USART_RX_STA |= 0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA & 0X3FFF] = res;
					USART_RX_STA++;
					if (USART_RX_STA > (USART_REC_LEN - 1))
						USART_RX_STA = 0; // 接收数据错误,重新开始接收
				}
			}
		}
		// USART2->SR &= ~(1<<5);
	}
}

void USART2_SendStrings(const unsigned char *str, size_t size)
{
	size_t i;
	uint8_t ch;
	// size_t	retry;
	for (i = 0; i < size; i++)
	{
		ch = *(str + i);
		USART_SendData(USART2, ch);
		while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
		{
		};
	}
}
