#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "cefu.h"
#include "delay.h"
#include "square.h"
#include "change.h"
#include "cepin.h"
#include "frece.h"
#define u_fifo_size 8192
////////////////方波测幅变量//////////////////
extern float voltage_amp1,voltage_amp2;             //信号的幅值
extern u16 vol_maxnum1,vol_minnum1;                //8192个ad采样数据的最大最小值；
extern u16 vol_maxnum2,vol_minnum2;
extern u16 fifo_data1[u_fifo_size];          //8192个ad1采样数据
extern u16 fifo_data2[u_fifo_size];          //8192个ad2采样数据
extern u32 M;	//频率字
extern u32 fs;	//待测信号频率
float up_time,down_time;
int y=0,z=0;
float dutty;
extern float Um;
extern float fre_results;
extern float flag,v2;



void Um_text(void)
{
  frecey();
	cef_wd();
	u_vpp_test();
	duty(fifo_data1);
	time_up(fifo_data1);
	time_down(fifo_data1);
	Initgear();/////////////////////
	flag=0;////////初始化/////////
	change_switch();/////////////
}
//方波测幅//////////
float u_vpp_test(void)
{
	fs = 1000 * 8192.0 / (f32)(8192 + 1);		//计算采样频率
	M = 4294967296.0 * fs / 150000000.0;			//计算频率字
	u_trans_dds_consign();						//发送控制信号给FPGA
	//duty(fifo_data1);
	//time_up(fifo_data1);
	//time_down(fifo_data1);
	return u_vpp_deal();	//计算峰峰值
}
//AD控制
void u_trans_dds_consign(void)
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
	for(i = 0 ; i < u_fifo_size ; i++ ) 	//读取fifo1中的数据
	{
		fifo_data1[i] = *(vu16*)(p+0x10);
	}
	*(vu16*)(p+0x02) = 0x0011;

	//6.FIFO2读使能
	*(vu16*)(p+0x02) = 0x0039;				//fifo2读使能开启   //11_1001
	for(j = 0 ; j < u_fifo_size ; j++ ) 	//读取fifo2中的数据
	{
		//a=1010 1 0100=14
		fifo_data2[j] = *(vu16*)(p+0x14);
	}
}
float  u_vpp_deal()
{
	//1.获取高电平的最大值及其序号、低电平的最小值及其序号
	vol_maxnum1 = u_find_max1(fifo_data1);	//FIFO1最大值
	vol_minnum1 = u_find_min1(fifo_data1);	//FIFO1最小值
	vol_maxnum2 = find_max2(fifo_data2);	//FIFO2最大值
	vol_minnum2 = find_min2(fifo_data2);	//FIFO2最小值

	//2.计算幅值(基准电压2V，根据实际调整)
	//voltage_amp1 = (2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384;		//AD1峰峰值
	voltage_amp2 = (2.0 * (vol_maxnum2 - vol_minnum2) ) / 16384;	//AD2峰峰值
	//voltage_amp1 = 1.1952*(2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384+ 0.0561;//AD1校准峰峰值
	voltage_amp1 = 0.8071 *(1.1952*(2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384+ 0.0561)+0.1366;
	//voltage_amp2 = 0.8518 * (2.0 * (vol_maxnum2 - vol_minnum2) ) / 16384 + 0.3925;//AD2校准峰峰值
	
  Delay_us(1000);
	return voltage_amp1;
	//return voltage_amp2;
}

/////////方波最大值////////////
u16 u_find_max1(u16 *q)
{
	  u16 x,umax_data[u_fifo_size];
	  float u_mid1=0,u_mid2=0,u_max=0,m=0;
    int i,z=0;
		float data,mid=0;
	  u_mid1=find_max1(fifo_data1);////方波最大值///////////
	  u_mid2=find_min1(fifo_data1);
		mid=0.5f*u_mid1+0.5f*u_mid2;/////方波的中间值/////////
		for(x = 0; x < 8192; x++)
		{
			data=*q;
      if(data>mid)
			{
			if((*(q+1)-*q)*2/16384 < 0.1 && (*(q+1)-*q)*2/16384 > -0.1)
			{
				if((*q-*(q-1))*2/16384<0.1&& (*q-*(q-1))*2/16384>-0.1)
			  {
				 umax_data[z] =data;/////////////平滑的点存放在数组///////////
					z++;///////记录平滑点数//////
			  }
			 }
		  }
			q++;////////平移////////////
		}
		for(i=0;i<z;i++)
		{
			m=umax_data[i]+m;///////////平滑的点求和/////////////
		}
		u_max=m/z;/////////平均值为Umax////////
		return u_max;///////////返回Umax///////
}


//////////////方波最小值///////////////////
u16 u_find_min1(u16 *q)
{
	  u16 x,umin_data[u_fifo_size];
	  float u_mid1=0,u_mid2=0,u_min=0,m=0;
    int i,z=0;
		float data,mid=0;
	  u_mid1=find_max1(fifo_data1);////方波最大值///////////
	  u_mid2=find_min1(fifo_data1);
		mid=0.5f*u_mid1+0.5f*u_mid2;/////方波的中间值/////////
		for(x = 0; x < 8192; x++)
		{
			data=*q;
      if(data<mid)
			{
			if((*(q+1)-*q)*2/16384 < 0.1 && (*(q+1)-*q)*2/16384 > -0.1)
			{
				if((*q-*(q-1))*2/16384<0.1&& (*q-*(q-1))*16384>-0.1)
			  {
				 umin_data[z] =data;/////////////平滑的点存放在数组///////////
					z++;///////记录平滑点数//////
			  }
			 }
		  }
			q++;////////平移////////////
		}
		for(i=0;i<z;i++)
		{
			m=umin_data[i]+m;///////////平滑的点求和/////////////
		}
		u_min=m/z;/////////平均值为Umin////////
		return u_min;///////////返回Umin///////
}
//找到fifo1最小值

void duty(u16 *q)
{
	 int x;
	 float y=0,mid;
	 mid=v2;
			for(x = 0; x < u_fifo_size; x++)
		{
      if(*q*2/16384 >mid)
			y++;
			q++;
		}
		dutty=y/u_fifo_size;
}

void time_up(u16 *q )
{
	float i,x=0,y=0,x1=0;
	float m,n;
	float u_up1,up1,u_down1,u_up2,u_down2,mid,down1,up2,down2,mid9;
	//mid1=u_vpp_test();
	//mid2=u_find_min1(fifo_data1);
	mid= 0.1f*v2;/////////////0.1Um//////////
	mid9=0.9f*v2;
	for(i=0;i<u_fifo_size;i++)
	{
		if(*q*2/16384 < mid  && (*(q+1)*2/16384 > mid ))
		{
			u_up1=*q;////记录小于0.1Um的点///////
			up1=u_up1*2/16384 ;
			u_down1=*(q+1);
			down1=u_down1*2/16384 ;//////记录大于0.1Um的点///////
			x1=x;
		}
		if(*q*2/16384 < mid9  && (*(q+1)*2/16384 > mid9 ))
		{
			u_up2=*q;////记录小于0.9Um的点///////
			up2=u_up2*2/16384 ;
			u_down2=*(q+1);
			down2=u_down2*2/16384 ;//////记录大于0.9Um的点///////
			y=x;
		}
		x++;
		q++;
	}
	n=(mid -up1)/(down1-up1)+x1;///////0.1Um对应位置//////
	m=(9*mid-up2)/(down2-up2)+y;///////0.9Um对应位置//////
	up_time=(m-n)/(u_fifo_size*fre_results);////////上升时间//////////
}

void time_down(u16 *q )
{
	float i,x=0,m1=0,n1=0;
	float c,d;
	float u_up1,up1,u_down1,u_up2,u_down2,mid,down1,up2,down2,mid9;
	//mid1=u_vpp_test();
	//mid2=u_find_min1(fifo_data1);
	mid= 0.1f*v2;/////////////0.1Um//////////
	mid9=0.9f*v2;
	for(i=0;i<u_fifo_size;i++)
	{
		if(*q*2/16384 > mid9  && (*(q+1)*2/16384 < mid9 ))
		{
			u_up2=*q;////记录大于0.9Um的点///////
			up2=u_up2*2/16384 ;
			u_down2=*(q+1);
			down2=u_down2*2/16384 ;//////记录大于0.9Um的点///////
			n1=x;
		}
		if(*q*2/16384 > mid  && (*(q+1)*2/16384 < mid ))
		{
			u_up1=*q;////记录小于0.1Um的点///////
			up1=u_up1*2/16384 ;
			u_down1=*(q+1);
			down1=u_down1*2/16384 ;//////记录大于0.1Um的点///////
			m1=x;
		}
		x++;
		q++;
	}
	c=(mid-up1)/(down1-up1)+m1;///////0.9Um对应位置//////
	d=(9*mid-up2)/(down2-up2)+n1;///////0.1Um对应位置//////
	down_time=(c-d)/(u_fifo_size*fre_results);////////下降时间//////////
}
