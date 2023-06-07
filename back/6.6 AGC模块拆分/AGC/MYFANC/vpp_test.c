#include "vpp_test.h"
void vpp_test()
{
  fs = 1000 * 1024.0 / (f32)(1024 + 1); // 计算采样频率
  M = 4294967296.0 * fs / 150000000.0;  // 计算频率字
  trans_dds_consign();                  // 发送控制信号给FPGA
  vpp_deal();                           // 计算峰峰值
}