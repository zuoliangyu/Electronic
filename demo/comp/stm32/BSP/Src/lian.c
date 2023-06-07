#include "freavearg.h"

#include "zidonghuangdang.h"

int flag=0;
float fre_final;
	
float  frequency(void);  //测频函数声明
float average(void);
float fre_average(void);
float freall(void);  //频率检测以及加档函数定义



//频率检测函数
float average(void)
{
	int i;
	float avr;  //avr:存放三次平均值变量
	char a[3];
	for(i=0;i<3;i++)
	  a[i]=frequency();
	avr=(a[0]+a[1]+a[2])/3;
	return(avr);
}

//频率稳定判断
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
	abcd_switch(0);  //初始化 除10档
	
	
	/////flag标志位：flag=1时，说明频率稳定，则不加档；flag=0时，频率不稳定，加档
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