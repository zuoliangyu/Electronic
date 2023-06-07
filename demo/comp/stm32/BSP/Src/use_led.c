#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "usart0.h"
#include "delay.h"
#include "delay1.h"
#include "led.h"
#include "cepin.h"
#include "cefu.h"
#include "use_led.h"
#include "usart0.h"
#include "change.h"
#include "cepin.h"
extern float fre_results, v_avr, f_result, Um;
extern float voltage_amp1, voltage_amp2;
extern _ARMABI int strcmp(u8 * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1, 2)));
extern u8 USART_RX_BUF[USART_REC_LEN];
const u8 TEXT_Buffer[] = {"0123456789"};
extern u8 USART_RX_BUF[USART_REC_LEN];
extern u16 fifo_data1[fifo_size]; // 1024��ad1��������
extern u16 fifo_data2[fifo_size]; // 1024��ad2��������
u16 len;
extern void frecey(void);
extern float vpp_avr(void);

void function(void)
{
	int i;
	// HMI_Display_TxtChar("t0.txt","ok");
	HMI_Display_TxtFloat("t14.txt", voltage_amp1);
	HMI_Display_TxtFloat("t16.txt", fre_results);
	if (USART_RX_STA & 0x8000)
	{
		len = USART_RX_STA & 0x3fff; // �õ��˴ν��յ������ݳ���
		USART_RX_STA = 0;
		if (!(strcmp(USART_RX_BUF, "1")))
		{
			vpp_test();
			for (i = 0; i < fifo_size; i++)
			{
				fifo_data1[i] = fifo_data1[i] * 3;
				HMI_Wave('2', '0', fifo_data1[i] >> 31); // ��Ƶ��������
			}
		}
		if (!(strcmp(USART_RX_BUF, "2")))
		{
			LED0 = 1;
		}
		if (!(strcmp(USART_RX_BUF, "3"))) // ����һ
		{
			vpp_test();
			for (i = 0; i < fifo_size; i++)
			{
				// fifo_data1[i]=fifo_data1[i]*3;
				HMI_Wave('2', '0', fifo_data1[i] >> 6); // ��Ƶ��������
			}
		}
	}

	// HMI_Wave_Clear('2','0');
}