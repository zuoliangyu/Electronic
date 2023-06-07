#include "frece.h"
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "sys.h"

extern int gear,flag;
float f_result,fre_avr;

float freavearg()
{
	float fre[5]={0,0,0,0};
	int i;
				for(i=0;i<4;i++)
	 {
		fre[i]=frequency();
   }
	fre_avr=(fre[3]+fre[1]+fre[2])/3;
	return fre_avr;
}

void frecey(void)
{
	float fre_1,fre_2,fre_3,fre_4,fre_5;
		fre_1=freavearg();
	  fre_2=freavearg();
	  fre_3=freavearg();
	  fre_4=freavearg();
while( fre_3==0 )
{
		gear++;
		change_switch();
		fre_1=freavearg();
	  fre_2=freavearg();
	  fre_3=freavearg();
	  fre_4=freavearg();
}
fre_5=fre_4+fre_1-(fre_2+fre_3); 
	while( fre_5<-10||fre_5>10 )
	{
		gear++;
		change_switch();
		fre_1=freavearg();
	  fre_2=freavearg();
	  fre_3=freavearg();
		fre_4=freavearg();
		fre_5=fre_4+fre_1-(fre_2+fre_3); 
  }
	Initgear();
	change_switch();
	f_result=(fre_1+fre_2+fre_3+fre_4)/4;
}

