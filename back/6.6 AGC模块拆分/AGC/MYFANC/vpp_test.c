#include "vpp_test.h"
void vpp_test()
{
  fs = 1000 * 1024.0 / (f32)(1024 + 1); // �������Ƶ��
  M = 4294967296.0 * fs / 150000000.0;  // ����Ƶ����
  trans_dds_consign();                  // ���Ϳ����źŸ�FPGA
  vpp_deal();                           // ������ֵ
}