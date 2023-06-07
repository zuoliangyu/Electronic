#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "cefu.h"
#include "delay.h"
#include "frece.h"
#include "change.h"
#define fifo_size 1024
#define u_fifo_size 8192

////////////////�������//////////////////
float voltage_amp1,voltage_amp2,Y,A;             //�źŵķ�ֵ
u16 vol_maxnum1,vol_minnum1;                //1024��ad�������ݵ������Сֵ��
u16 vol_maxnum2,vol_minnum2,vol_dc;
u16 fifo_data1[fifo_size];          //1024��ad1��������
u16 fifo_data2[fifo_size];        //1024��ad2��������
u32 M;	//Ƶ����
u32 fs;	//�����ź�Ƶ��


//���
float vpp_test()
{
	fs = 1000 * 1024.0 / (f32)(1024 + 1);		//�������Ƶ��
	M = 4294967296.0 * fs / 150000000.0;			//����Ƶ����
	trans_dds_consign();							//���Ϳ����źŸ�FPGA
	return vpp_deal();	//������ֵ
}

//AD����
void trans_dds_consign(void)
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
	for(i = 0 ; i < fifo_size ; i++ ) 	//��ȡfifo1�е�����
	{
		fifo_data1[i] = *(vu16*)(p+0x10);
	}
	*(vu16*)(p+0x02) = 0x0011;

	//6.FIFO2��ʹ��
	*(vu16*)(p+0x02) = 0x0039;				//fifo2��ʹ�ܿ���   //11_1001
	for(j = 0 ; j < fifo_size ; j++ ) 	//��ȡfifo2�е�����
	{
		//a=1010 1 0100=14
		fifo_data2[j] = *(vu16*)(p+0x14);
	}
}

//�Բ������ݽ��д���
float  vpp_deal()
{
	//1.��ȡ�ߵ�ƽ�����ֵ������š��͵�ƽ����Сֵ�������
	vol_maxnum1 = find_max1(fifo_data1);	//FIFO1���ֵ
	vol_minnum1 = find_min1(fifo_data1);	//FIFO1��Сֵ
	vol_maxnum2 = find_max1(fifo_data2);	//FIFO2���ֵ
	vol_minnum2 = find_min2(fifo_data2);	//FIFO2��Сֵ
  vol_dc = DC_use();
	//2.�����ֵ(��׼��ѹ2V������ʵ�ʵ���)
	//voltage_amp1 = (2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384;		//AD1���ֵ
	//voltage_amp2 = (2.0 * (vol_maxnum2 - vol_minnum2) ) / 16384;	//AD2���ֵ
	//voltage_amp1 = 1.1952*(2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384+ 0.0561;//AD1У׼���ֵ
	voltage_amp1 = 0.8071 *(1.1952*(2.0 * (vol_maxnum1 - vol_minnum1) ) / 16384+ 0.0561)+0.1366;
	//voltage_amp2 = 0.8518 * (2.0 * (vol_maxnum2 - vol_minnum2) ) / 16384 + 0.3925;//AD2У׼���ֵ
	voltage_amp2 = (2.0 * vol_dc ) / 16384; //AD2���ֵ��ֱ����
  Delay_us(100);
	return voltage_amp1;               
}

//�ҵ�fifo1���ֵ
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

//�ҵ�fifo1��Сֵ
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

//�ҵ�fifo2���ֵ
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

//�ҵ�fifo2��Сֵ
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
//ֱ������
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



