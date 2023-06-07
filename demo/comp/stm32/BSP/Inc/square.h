#include "stm32f4xx.h"
#ifndef _SQUARE_H_
#define _DQUARE_H_
#define u_fifo_size 8192
#define p  ((u32)(0x68000000))
////////方波测幅函数/////////////////
u16 u_find_max1(u16 *q);/////方波最大值
u16 u_find_min1(u16 *q);/////方波最小值
float u_vpp_deal(void);
float u_vpp_test(void);
void time_up(u16 *q );
void time_down(u16 *q );
void duty(u16 *q);
void Um_text(void);
extern float vpp_avr(void);
void u_trans_dds_consign(void);
void trans_dds_consign(void);
extern u16 find_min1(u16 *q);              //最小值函数
extern u16 find_max1(u16 *q);              //最大值函数
extern u16 find_min2(u16 *q);              //最小值函数
extern u16 find_max2(u16 *q);              //最大值函数
#endif
