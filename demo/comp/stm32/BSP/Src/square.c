#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "cefu.h"
#include "delay.h"
#include "square.h"
#include "change.h"
#include "cepin.h"
#include "frece.h"
#define u_fifo_size 8192
////////////////�����������//////////////////
extern float voltage_amp1,voltage_amp2;             //�źŵķ�ֵ
extern u16 vol_maxnum1,vol_minnum1;                //8192��ad�������ݵ������Сֵ��
extern u16 vol_maxnum2,vol_minnum2;
extern u16 fifo_data1[u_fifo_size];          //8192��ad1��������
extern u16 fifo_data2[u_fifo_size];          //8192��ad2��������
extern u32 M;	//Ƶ����
extern u32 fs;	//�����ź�Ƶ��
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
	flag=0;////////��ʼ��/////////
	change_switch();/////////////
}
//�������//////////
float u_vpp_test(void)
{
	fs = 1000 * 8192.0 / (f32)(8192 + 1);		//�������Ƶ��
	M = 4294967296.0 * fs / 150000000.0;			//����Ƶ����
	u_trans_dds_consign();						//���Ϳ����źŸ�FPGA
	//duty(fifo_data1);
	//time_up(fifo_data1);
	//time_down(fifo_data1);
	return u_vpp_deal();	//������ֵ
}
//AD����
void u_trans_dds_consign(void)
{
	int i,j;

	//MΪ32λ���ݣ���˷����Σ���16λ�͵�16λ������

	//1.����M�ĸ�16λ	6=110	1100
	*(vu16*)(p+0x0c) = (u32)M >> 16;
	Delay_us(1000);

	//2.����M�ĵ�16λ	7=111	1110
	*(vu16*)(p+0x0e) = (u32)M & 0x0000ffff;;
	Delay_us(1000);

	//3.ʹ�ܣ����fs�����ź�
	*(vu16*)(p+0x2) = 0x0011;
	Delay_us(1000);

	//�ȴ�������ɣ���fifoд��

	//4.FIFOдʹ��
	*(vu16*)(p+0x2) = 0x0015;	//fifoдʹ�ܿ�����ͬʱҪ����ADת������
	while ( *(vu16*)(p+0x12) != 0x0001 ) ;	//�ȴ�fifo1д��
	while ( *(vu16*)(p+0x16) != 0x0001 ) ;	//�ȴ�fifo2д��
	*(vu16*)(p+0x02) = 0x0011;
	Delay_us(1000);

	//5.FIFO1��ʹ��
	*(vu16*)(p+0x02) = 0x0019;	//fifo1��ʹ�ܿ���
	for(i = 0 ; i < u_fifo_size ; i++ ) 	//��ȡfifo1�е�����
	{
		fifo_data1[i] = *(vu16*)(p+0x10);
	}
	*(vu16*)(p+0x02) = 0x0011;

	//6.FIFO2��ʹ��
	*(vu16*)(p+0x02) = 0x0039;				//fifo2��ʹ�ܿ���   //11_1001
	for(j = 0 ; j < u_fifo_size ; j++ ) 	//��ȡfifo2�е�����
	{
		//a=1010 1 0100=14
		fifo_data2[j] = *(vu16*)(p+0x14);
	}
}
float  u_vpp_deal()
{
	//1.��ȡ�ߵ�ƽ�����ֵ������š��͵�ƽ����Сֵ�������
	vol_maxnum1 = u_find_max1(fifo_data1);	//FIFO1���ֵ
	vol_minnum1 = u_find_min1(fifo_data1);	//FIFO1��Сֵ
	vol_maxnum2 = find_max2(fifo_data2);	//FIFO2���ֵ
	vol_minnum2 = find_min2(fifo_data2);	//FIFO2��Сֵ

	//2.�����ֵ(��׼��ѹ2V������ʵ�ʵ���)
	//voltage_amp1 = (2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384;		//AD1���ֵ
	voltage_amp2 = (2.0 * (vol_maxnum2 - vol_minnum2) ) / 16384;	//AD2���ֵ
	//voltage_amp1 = 1.1952*(2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384+ 0.0561;//AD1У׼���ֵ
	voltage_amp1 = 0.8071 *(1.1952*(2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384+ 0.0561)+0.1366;
	//voltage_amp2 = 0.8518 * (2.0 * (vol_maxnum2 - vol_minnum2) ) / 16384 + 0.3925;//AD2У׼���ֵ
	
  Delay_us(1000);
	return voltage_amp1;
	//return voltage_amp2;
}

/////////�������ֵ////////////
u16 u_find_max1(u16 *q)
{
	  u16 x,umax_data[u_fifo_size];
	  float u_mid1=0,u_mid2=0,u_max=0,m=0;
    int i,z=0;
		float data,mid=0;
	  u_mid1=find_max1(fifo_data1);////�������ֵ///////////
	  u_mid2=find_min1(fifo_data1);
		mid=0.5f*u_mid1+0.5f*u_mid2;/////�������м�ֵ/////////
		for(x = 0; x < 8192; x++)
		{
			data=*q;
      if(data>mid)
			{
			if((*(q+1)-*q)*2/16384 < 0.1 && (*(q+1)-*q)*2/16384 > -0.1)
			{
				if((*q-*(q-1))*2/16384<0.1&& (*q-*(q-1))*2/16384>-0.1)
			  {
				 umax_data[z] =data;/////////////ƽ���ĵ���������///////////
					z++;///////��¼ƽ������//////
			  }
			 }
		  }
			q++;////////ƽ��////////////
		}
		for(i=0;i<z;i++)
		{
			m=umax_data[i]+m;///////////ƽ���ĵ����/////////////
		}
		u_max=m/z;/////////ƽ��ֵΪUmax////////
		return u_max;///////////����Umax///////
}


//////////////������Сֵ///////////////////
u16 u_find_min1(u16 *q)
{
	  u16 x,umin_data[u_fifo_size];
	  float u_mid1=0,u_mid2=0,u_min=0,m=0;
    int i,z=0;
		float data,mid=0;
	  u_mid1=find_max1(fifo_data1);////�������ֵ///////////
	  u_mid2=find_min1(fifo_data1);
		mid=0.5f*u_mid1+0.5f*u_mid2;/////�������м�ֵ/////////
		for(x = 0; x < 8192; x++)
		{
			data=*q;
      if(data<mid)
			{
			if((*(q+1)-*q)*2/16384 < 0.1 && (*(q+1)-*q)*2/16384 > -0.1)
			{
				if((*q-*(q-1))*2/16384<0.1&& (*q-*(q-1))*16384>-0.1)
			  {
				 umin_data[z] =data;/////////////ƽ���ĵ���������///////////
					z++;///////��¼ƽ������//////
			  }
			 }
		  }
			q++;////////ƽ��////////////
		}
		for(i=0;i<z;i++)
		{
			m=umin_data[i]+m;///////////ƽ���ĵ����/////////////
		}
		u_min=m/z;/////////ƽ��ֵΪUmin////////
		return u_min;///////////����Umin///////
}
//�ҵ�fifo1��Сֵ

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
			u_up1=*q;////��¼С��0.1Um�ĵ�///////
			up1=u_up1*2/16384 ;
			u_down1=*(q+1);
			down1=u_down1*2/16384 ;//////��¼����0.1Um�ĵ�///////
			x1=x;
		}
		if(*q*2/16384 < mid9  && (*(q+1)*2/16384 > mid9 ))
		{
			u_up2=*q;////��¼С��0.9Um�ĵ�///////
			up2=u_up2*2/16384 ;
			u_down2=*(q+1);
			down2=u_down2*2/16384 ;//////��¼����0.9Um�ĵ�///////
			y=x;
		}
		x++;
		q++;
	}
	n=(mid -up1)/(down1-up1)+x1;///////0.1Um��Ӧλ��//////
	m=(9*mid-up2)/(down2-up2)+y;///////0.9Um��Ӧλ��//////
	up_time=(m-n)/(u_fifo_size*fre_results);////////����ʱ��//////////
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
			u_up2=*q;////��¼����0.9Um�ĵ�///////
			up2=u_up2*2/16384 ;
			u_down2=*(q+1);
			down2=u_down2*2/16384 ;//////��¼����0.9Um�ĵ�///////
			n1=x;
		}
		if(*q*2/16384 > mid  && (*(q+1)*2/16384 < mid ))
		{
			u_up1=*q;////��¼С��0.1Um�ĵ�///////
			up1=u_up1*2/16384 ;
			u_down1=*(q+1);
			down1=u_down1*2/16384 ;//////��¼����0.1Um�ĵ�///////
			m1=x;
		}
		x++;
		q++;
	}
	c=(mid-up1)/(down1-up1)+m1;///////0.9Um��Ӧλ��//////
	d=(9*mid-up2)/(down2-up2)+n1;///////0.1Um��Ӧλ��//////
	down_time=(c-d)/(u_fifo_size*fre_results);////////�½�ʱ��//////////
}
