#include "usart_base.h"
#include "usart2.h"
#include "stm32f4xx_usart.h"
#include "sys.h"

/////////////////////////////////////////////////////////////////
// �������´���,֧��printf����,������Ҫѡ��use MicroLIB
#if USART == 2
#pragma import(__use_no_semihosting)
// ��׼����Ҫ��֧�ֺ���
struct __FILE
{
	int handle;
};

FILE __stdout;
// ����_sys_exit()�Ա���ʹ�ð�����ģʽ
void _sys_exit(int x)
{
	x = x;
}
// �ض���fputc����
int fputc(int ch, FILE *f)
{
	while ((USART2->SR & 0X40) == 0)
		; // ѭ������,ֱ���������
	USART2->DR = (uint8_t)ch;
	return ch;
}

// ����1�жϷ������
// ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���
uint8_t USART_RX_BUF[USART_REC_LEN]; // ���ջ���,���USART_REC_LEN���ֽ�.
// ����״̬
// bit15��	������ɱ�־
// bit14��	���յ�0x0d
// bit13~0��	���յ�����Ч�ֽ���Ŀ
u16 USART_RX_STA = 0; // ����״̬���
#endif

// ��ʼ��IO ����1
// bound:������
void USART2_Config(uint32_t bound)
{
	// GPIO�˿�����
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	 // ʹ��GPIOAʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); // ʹ��USART2ʱ��

	// ����2��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); // GPIOA2����ΪUSART2
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2); // GPIOA10����ΪUSART2

	// USART1�˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; // GPIOA2��GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;					 // ���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			 // �ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;				 // ���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;					 // ����
	GPIO_Init(GPIOA, &GPIO_InitStructure);								 // ��ʼ��PA2��PA3

	// USART1 ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;																			// ����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;											// �ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;													// һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;															// ����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // ��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;									// �շ�ģʽ
	USART_Init(USART2, &USART_InitStructure);																				// ��ʼ������1

	USART_Cmd(USART2, ENABLE); // ʹ�ܴ���1

#if EN_USART2_RX
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // ��������ж�

	// Usart1 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;					// ����1�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3; // ��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;				// �����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;						// IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);														// ����ָ���Ĳ�����ʼ��VIC�Ĵ�����

#endif
}

void USART2_IRQHandler(void)
{
	u8 res;
	if (USART2->SR & (1 << 5)) // ���յ�����
	{
		res = USART2->DR;
		if ((USART_RX_STA & 0x8000) == 0) // ����δ���
		{
			if (USART_RX_STA & 0x4000) // ���յ���0x0d
			{
				if (res != 0x0a)
					USART_RX_STA = 0; // ���մ���,���¿�ʼ
				else
					USART_RX_STA |= 0x8000; // ���������
			}
			else // ��û�յ�0X0D
			{
				if (res == 0x0d)
					USART_RX_STA |= 0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA & 0X3FFF] = res;
					USART_RX_STA++;
					if (USART_RX_STA > (USART_REC_LEN - 1))
						USART_RX_STA = 0; // �������ݴ���,���¿�ʼ����
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
