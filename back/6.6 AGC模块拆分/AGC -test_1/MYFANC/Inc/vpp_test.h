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
////////////////测幅函数//////////////////
void AD_get();                // 进行直流测量
void vpp_test();              // 测幅函数定义
void trans_dds_consign(void); // 调用dds
float vpp_deal(void);         // 对幅度进行测量
u16 find_min(u16 *q);         // 最小值函数
u16 find_max(u16 *q);         // 最大值函数
void vpp_test_AGC();          // AGC测量
#endif