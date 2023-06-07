#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "cefu.h"
#include "delay.h"
#include "frece.h"
#include "change.h"
#define fifo_size 1024
#define u_fifo_size 8192

////////////////测幅变量//////////////////
float voltage_amp1,voltage_amp2,Y,A;             //信号的幅值
u16 vol_maxnum1,vol_minnum1;                //1024个ad采样数据的最大最小值；
u16 vol_maxnum2,vol_minnum2,vol_dc;
u16 fifo_data1[fifo_size];          //1024个ad1采样数据
u16 fifo_data2[fifo_size];        //1024个ad2采样数据
u32 M;	//频率字
u32 fs;	//待测信号频率


//测幅
float vpp_test()
{
	fs = 1000 * 1024.0 / (f32)(1024 + 1);		//计算采样频率
	M = 4294967296.0 * fs / 150000000.0;			//计算频率字
	trans_dds_consign();							//发送控制信号给FPGA
	return vpp_deal();	//计算峰峰值
}

//AD控制
void trans_dds_consign(void)
{
	int i,j;

	//M为32位数据，因此分两次（高16位和低16位）发送

	//1.发送M的高16位	6=110	1100
	*(vu16*)(p+0x0c) = (u32)M >> 16;
	Delay_us(1000);

	//2.发送M的低16位	7=111	1110
	*(vu16*)(p+0x0e) = (u32)M & 0x0000ffff;;
	Delay_us(1000);

	//3.使能，输出fs采样信号
	*(vu16*)(p+0x2) = 0x0011;
	Delay_us(1000);

	//等待采样完成，即fifo写满

	//4.FIFO写使能
	*(vu16*)(p+0x2) = 0x0015;	//fifo写使能开启，同时要开启AD转换功能
	while ( *(vu16*)(p+0x12) != 0x0001 ) ;	//等待fifo1写满
	while ( *(vu16*)(p+0x16) != 0x0001 ) ;	//等待fifo2写满
	*(vu16*)(p+0x02) = 0x0011;
	Delay_us(1000);

	//5.FIFO1读使能
	*(vu16*)(p+0x02) = 0x0019;	//fifo1读使能开启
	for(i = 0 ; i < fifo_size ; i++ ) 	//读取fifo1中的数据
	{
		fifo_data1[i] = *(vu16*)(p+0x10);
	}
	*(vu16*)(p+0x02) = 0x0011;

	//6.FIFO2读使能
	*(vu16*)(p+0x02) = 0x0039;				//fifo2读使能开启   //11_1001
	for(j = 0 ; j < fifo_size ; j++ ) 	//读取fifo2中的数据
	{
		//a=1010 1 0100=14
		fifo_data2[j] = *(vu16*)(p+0x14);
	}
}

//对采样数据进行处理
float  vpp_deal()
{
	//1.获取高电平的最大值及其序号、低电平的最小值及其序号
	vol_maxnum1 = find_max1(fifo_data1);	//FIFO1最大值
	vol_minnum1 = find_min1(fifo_data1);	//FIFO1最小值
	vol_maxnum2 = find_max1(fifo_data2);	//FIFO2最大值
	vol_minnum2 = find_min2(fifo_data2);	//FIFO2最小值
  vol_dc = DC_use();
	//2.计算幅值(基准电压2V，根据实际调整)
	//voltage_amp1 = (2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384;		//AD1峰峰值
	//voltage_amp2 = (2.0 * (vol_maxnum2 - vol_minnum2) ) / 16384;	//AD2峰峰值
	//voltage_amp1 = 1.1952*(2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384+ 0.0561;//AD1校准峰峰值
	voltage_amp1 = 0.8071 *(1.1952*(2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384+ 0.0561)+0.1366;
	//voltage_amp2 = 0.8518 * (2.0 * (vol_maxnum2 - vol_minnum2) ) / 16384 + 0.3925;//AD2校准峰峰值
	voltage_amp2 = (2.0 * vol_dc ) / 16384; //AD2峰峰值（直流）
  Delay_us(100);
	return voltage_amp1;               
}

//找到fifo1最大值
u16 find_max1(u16 *q)
{
	  u16 x;		
		u16 max = *q;

		for(x = 0; x < fifo_size; x++)
		{
			if(*q > max)
			  {
				 max = *q;
			  }
		   q++;
		}
		return max;	
}

//找到fifo1最小值
u16 find_min1(u16 *q)
{ 
	u16 x;
		u16 min = *q;
		for(x = 0; x <fifo_size; x++)
		{
			if(*q < min)
			{
				min = *q;

			}
			q++;
		}
		return min;
}

//找到fifo2最大值
u16 find_max2(u16 *q)
{
	  u16 x;		
		u16 max = *q;

		for(x = 0; x < fifo_size; x++)
		{
			if(*q > max)
			  {
				 max = *q;
			  }
		   q++;
		}
		return max;	
}

//找到fifo2最小值
u16 find_min2(u16 *q)
{ 
	u16 x;
		u16 min = *q;
		for(x = 0; x <fifo_size; x++)
		{
			if(*q < min)
			{
				min = *q;
			}
			q++;
		}
		return min;
}
//直流测量
float DCmesure(u16 *q)
{
	float m=0;
	int i;
	for(i=0;i<fifo_size;i++)
	{
	m=m+fifo_data2[i];
	}
	Y=m/fifo_size;
}
float DC_use()
{
	int i,DC[4],m=0,Y;
	for(i=0;i<5;i++)
	{
		DC[i]=DCmesure(fifo_data2);
		m=m+DC[i];
	}
	Y=m/5;
	return  Y;
}



