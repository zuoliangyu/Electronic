#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "vpp_test.h"


#define fifo_size 1024
#define p  ((u32)(0x68000000)) //FSMC--BANK1--SRAM3的首地址

////////////////测幅变量//////////////////
float voltage_amp1,voltage_amp2;             //信号的幅值
u16 vol_maxnum1,vol_minnum1;                   //1024个ad采样数据的最大最小值；
u16 vol_maxnum2,vol_minnum2;
u16 fifo_data1[fifo_size];          //1024个ad1采样数据
u16 fifo_data2[fifo_size];          //1024个ad2采样数据
u32 M;	//频率字
u32 fs;	//待测信号频率



//测幅
void vpp_test(void)
{
	fs = 1000 * 1024.0 / (f32)(1024 + 1);		//??????
	M = 4294967296.0 * fs / 150000000.0;			//?????
	trans_dds_consign();							//??????????FPGA,???FPGA????
	dds_deal();
}

//AD控制
void trans_dds_consign(void)
{
	int i,j;
	//u16 *p = 0x00000000;
	//p=(unsigned int *)0x00100000;	//??FPGA??

	//M为32位数据，因此分两次（高16位和低16位）发送

	//1.发送M的高16位	6=110	1100=8+4
	//*(p + 0x06) = (Uint32)M >> 16;
	*(vu16*)(p+0x0c) = (u32)M >> 16;
	Delay_us(1000);

	//2.发送M的低16位	7=111	1110
	//*(p + 0x07) = (Uint32)M & 0x0000ffff;
	*(vu16*)(p+0x0e) = (u32)M & 0x0000ffff;;
	Delay_us(1000);

	//3.使能，输出fs采样信号
	//*(p + 0x01) = 0x0011;		//  1_0001
	*(vu16*)(p+0x2) = 0x0011;
	Delay_us(1000);

	//等待采样完成，即fifo写满

	//4.FIFO写使能
	//*(p + 0x01) = 0x0015;			//FIFO?????,?????AD????        01_0101
	//while(*(p + 0x09) != 0x0001);  	//??FIFO????
	//while(*(p + 0x0b) != 0x0001);  	//??FIFO2????
	//*(p + 0x01) = 0x0011;			//FIFO?????        01_0001
	
	*(vu16*)(p+0x2) = 0x0015;	//fifo写使能开启，同时要开启AD转换功能
	//9=1001 1 0010
	//b=11=1011 1 0110
	//while ( *(vu16*)(p+0x12) != 0x0001 ) ;	//等待fifo1写满
	while ( *(vu16*)(p+0x16) != 0x0001 ) ;	//等待fifo2写满
	*(vu16*)(p+0x02) = 0x0011;
	Delay_us(1000);

	//5.FIFO1读使能
	//*(p + 0x01) = 0x0019;				//FIFO?????     //01_1001
	//for(i = 0 ; i < FIFO_SIZE ; i++ ) 	//??FIFO??1024???
	//{
		//fifo_data[i] = *(p + 0x08);
		//fifo_voltage_amp[i] = (2.0 * fifo_data[i] ) / 16384;
	//}
	//*(p + 0x01) = 0x0011;				//FIFO?????,??????????   //01_0001
	
	//1000    1 0000
	//*(vu16*)(p+0x02) = 0x0019;
	//for(i = 0 ; i < fifo_size ; i++ ) 	//??FIFO??1024???
	//{
		//fifo_data1[i] = *(vu16*)(p+0x10);
	//}
	//*(vu16*)(p+0x02) = 0x0011;

//	6.FIFO2读使能
	//*(p + 0x01) = 0x0039;				//FIFO2?????     //11_1001
	//for(j = 0 ; j < FIFO_SIZE ; j++ ) 	//??FIFO??1024???
	//{
		//fifo_data2[j] = *(p + 0x0a);
	//}
	*(vu16*)(p+0x02) = 0x0039;				//FIFO2?????     //11_1001
	for(j = 0 ; j < fifo_size ; j++ ) 	//??FIFO??1024???
	{
		//a=1010 1 0100=14
		fifo_data2[j] = *(vu16*)(p+0x14);
	}
}

//对采样数据进行处理
void dds_deal(void)
{
	//1.获取高电平的最大值及其序号、低电平的最小值及其序号
	vol_maxnum1 = find_max1(fifo_data1);	//FIFO???
	vol_minnum1 = find_min1(fifo_data1);	//FIFO???
	vol_maxnum2 = find_max2(fifo_data2);	//FIFO2???
	vol_minnum2 = find_min2(fifo_data2);	//FIFO2???

	//2.????(????2V)
	//voltage_amp = (5.0 * (vol_maxnum1 - vol_minnum1) ) / 16384;		//FIFO??
	voltage_amp2 = (2.0 * (vol_maxnum2 - vol_minnum2) ) / 16384;	//FIFO2?
Delay_us(1000);
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
