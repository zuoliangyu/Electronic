#include "frequency.h"
////////////////测频变量//////////////////
u32 count_fx, count_base;     // 待测信号上升沿计数值、基准时钟上升沿计数值
u32 tmp_low, tmp_high;        // 高低数值
float fre_results;            // 信号的频率值
#define p ((u32)(0x68000000)) // FSMC--BANK1--SRAM3的首地址
// 测频
float frequency(void)
{
  ///////////////控制信号////////////////
  // u32 *p=0x68000000;
  *(vu16 *)(p + 0x02) = 0x0000; // 0_0000	计数器清零，使能关闭
  Delay_us(10);
  *(vu16 *)(p + 0x02) = 0x0001; // 0_0001  计数器不清零 使能关闭
  Delay_us(10);
  *(vu16 *)(p + 0x02) = 0x0003; // 0_0011  计数器不清零 使能打开，开始计数，计数时间给1s
  Delay_us(100000);
  *(vu16 *)(p + 0x02) = 0x0001; // 0_0001	计数器不清零  使能关闭。
  /////////////获取数据///////////
  // 待测信号计数值
  tmp_high = *(vu16 *)(p + 0x04); // 高16	100
  Delay_us(1000);
  tmp_low = *(vu16 *)(p + 0x06); // 低16	110
  Delay_us(1000);
  count_fx = tmp_low + (tmp_high << 16);
  Delay_us(1000);
  // 基准时钟计数值
  tmp_high = *(vu16 *)(p + 0x08); // 高16	1000
  Delay_us(1000);
  tmp_low = *(vu16 *)(p + 0x0a); // 低16	1010
  Delay_us(1000);
  count_base = tmp_low + (tmp_high << 16);
  Delay_us(1000);
  // 计算频率
  fre_results = 150000000.0 / count_base * count_fx;
  if (fre_results == 0)
  {
    fre_results = 1000; // 没有接入测频的时候就默认为1khz
  }
  return fre_results;
}