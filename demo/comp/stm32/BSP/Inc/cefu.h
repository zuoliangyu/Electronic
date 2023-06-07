#include "stm32f4xx.h"
#ifndef _CEFU_H_
#define _CEFU_H_
#define fifo_size 1024
#define p  ((u32)(0x68000000))

////////////////测幅函数//////////////////
float vpp_test(void);          //测幅函数定义
void trans_dds_consign(void);
float  vpp_deal(void);
void Initgear(void);
void add(void);
u16 find_min1(u16 *q);              //最小值函数
u16 find_max1(u16 *q);              //最大值函数
u16 find_min2(u16 *q);              //最小值函数
u16 find_max2(u16 *q);              //最大值函数
float DC_use();                     //直流测量
#endif
