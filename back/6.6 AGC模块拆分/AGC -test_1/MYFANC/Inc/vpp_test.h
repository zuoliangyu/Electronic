#ifndef vpp_test
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "clk.h"
#include "led.h"
#include "delay.h"
#include "adc.h"
#include "usart1.h"
#include "key.h"
#include "i2s3.h"
#include "w25qxx.h"
#include "exti.h"
#include "iwdg.h"
#include "wwdg.h"
#include "24Cxx.h"
#include "usart2.h"
#include <string.h>
#include "fsmc.h"
#include "malloc.h"
#include "debug.h"
#include "adc.h"
#include <math.h>
////////////////�������//////////////////
void AD_get();                // ����ֱ������
void vpp_test();              // �����������
void trans_dds_consign(void); // ����dds
float vpp_deal(void);         // �Է��Ƚ��в���
u16 find_min(u16 *q);         // ��Сֵ����
u16 find_max(u16 *q);         // ���ֵ����
void vpp_test_AGC();          // AGC����
#endif