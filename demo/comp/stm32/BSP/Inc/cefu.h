#include "stm32f4xx.h"
#ifndef _CEFU_H_
#define _CEFU_H_
#define fifo_size 1024
#define p  ((u32)(0x68000000))

////////////////�������//////////////////
float vpp_test(void);          //�����������
void trans_dds_consign(void);
float  vpp_deal(void);
void Initgear(void);
void add(void);
u16 find_min1(u16 *q);              //��Сֵ����
u16 find_max1(u16 *q);              //���ֵ����
u16 find_min2(u16 *q);              //��Сֵ����
u16 find_max2(u16 *q);              //���ֵ����
float DC_use();                     //ֱ������
#endif
