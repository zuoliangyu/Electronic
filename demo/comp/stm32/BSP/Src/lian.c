#include "freavearg.h"

#include "zidonghuangdang.h"

int flag=0;
float fre_final;
	
float  frequency(void);  //��Ƶ��������
float average(void);
float fre_average(void);
float freall(void);  //Ƶ�ʼ���Լ��ӵ���������



//Ƶ�ʼ�⺯��
float average(void)
{
	int i;
	float avr;  //avr:�������ƽ��ֵ����
	char a[3];
	for(i=0;i<3;i++)
	  a[i]=frequency();
	avr=(a[0]+a[1]+a[2])/3;
	return(avr);
}

//Ƶ���ȶ��ж�
float fre_average(void)
{
	float f1,f2,f3;
	f1=average();
	f2=average();	
	f3=average();	
	if(-1<(f3-2*f2+f1)<1)
	{	
	  fre_final=(f1+f2+f3)/3;
	  flag=1;
		return(fre_final);
	}
	return 0;
}

float freall(void)
{

	fre_final=fre_average();
	abcd_switch(0);  //��ʼ�� ��10��
	
	
	/////flag��־λ��flag=1ʱ��˵��Ƶ���ȶ����򲻼ӵ���flag=0ʱ��Ƶ�ʲ��ȶ����ӵ�
	if(flag==0)
	{
		{
		abcd_switch(1);
		fre_final=fre_average();
		}
		if(flag==0)
		{
			abcd_switch(2);
			fre_final=fre_average();
		}
		  if(flag==0)
			{
				abcd_switch(3);
				fre_final=fre_average();
			}
				
			  if(flag==0)
				{	
			   	abcd_switch(4);
					fre_final=fre_average();
					return 0;	
				}
	}
	return 0;
}