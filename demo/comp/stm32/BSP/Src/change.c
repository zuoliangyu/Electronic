#include "change.h"
#include "stm32f4xx_gpio.h"
#include "cefu.h"
#include "cepin.h"
#include "math.h"
#include "square.h"
#include "frece.h"

float v2,v,v_avr,Um;
int gear=0,flag=0;

void change_Config()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	/* GPIOC Peripheral clock enable */
  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//简单的电平输出可配置为OUT/IN模式,否则为AF
 	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//简单的电平输出可配置为OUT/IN模式,否则为AF
 	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//简单的电平输出可配置为OUT/IN模式,否则为AF
 	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);
		
		  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//简单的电平输出可配置为OUT/IN模式,否则为AF
 	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOA, &GPIO_InitStructure);
		
		  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

  	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//简单的电平输出可配置为OUT/IN模式,否则为AF
 	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOG, &GPIO_InitStructure);
		
		
	//探索者开发板采用的是类似共阳极的接法。
	//if()
}

 void change_switch()
{
	if(flag==0) CHANGE3 = 0 ;
	    else    CHANGE3 = 1 ;
		switch(gear) 
	{
		case 0:
    CHANGE0 = 0;
	  CHANGE1 = 0;
	  CHANGE2 = 0;
	  //CHANGE3 = 0;
	  //CHANGE4 = 0;
	  break;
		case 1:
		CHANGE0 = 1;
	  CHANGE1 = 0;
	  CHANGE2 = 0;
	  //CHANGE3 = 0;
	  //CHANGE4 = 0;
		break;
		case 2:
		CHANGE0 = 1;
	  CHANGE1 = 1;
	  CHANGE2 = 0;
	  //CHANGE3 = 0;
	  //CHANGE4 = 0;
		break;
		case 3:
		CHANGE0 = 1;
	  CHANGE1 = 1;
	  CHANGE2 = 1;
	  //CHANGE3 = 0;
	  //CHANGE4 = 0;
		break;
		//case 4:
	  //CHANGE0 = 1;
	 // CHANGE1 = 1;
	  //CHANGE2 = 1;
	 // CHANGE3 = 1;
	 // CHANGE4 = 1;
		//break;
 }
}

void Initgear(void)
{
	gear=0;
}

float vpp_avr()
{
	float v[6];
	int i;
			for(i=0;i<6;i++)
	 {
		v[i]=vpp_test();
		//v[i]=u_vpp_test();////方波
   }
	v_avr=(v[5]+v[1]+v[2]+v[3]+v[4])/5;
	return v_avr;
}

void cef_wd()
{
	flag=1;
	change_switch();
	v2=vpp_avr()-0.24f;
	while(!(v2 > 0.24f && v2 < 2.0f))
	{
		 if(v2 > 2.0f)
			 gear--;
		 if(v2 < 0.24f )
			 gear++;
		 change_switch();
		 v2=vpp_avr()-0.24f;
	}
	 //v=v2/powf(10.f,gear -1);
	 //v=1.3405*(v2/powf(10.f,gear -1))-3.2953;///10校正
	 //v=v2/powf(10.f,1);//x1
	 //v=1.154*(v2/powf(10.f,0))-0.1794;//x1校正
	 //v= 1.421*(v2/powf(10.f,1))-0.042;x10
	 //v=1.8075*(v2/powf(10.f,2))-0.0066;
	//v=1.0152*(1.8075*(v2/powf(10.f,2))-0.0066)-8E-05;
	 vpp_v();//恢复
	 Um=vpp_v();
	 Initgear();/////////////////////
	 flag=0;////////初始化/////////
	 change_switch();/////////////
}

float vpp_v(void )
{
	switch (gear)
	{
		//case 0:v=1.3405*(v2/powf(10.f,gear -1))-3.2953;break;///10校正
		case 0:v=v2/powf(10.f,-1);break;
		case 1:v=v2/powf(10.f,0);break;//x1
		case 2:v=v2/powf(10.f,1);break;//x10
		case 3:v=v2/powf(10.f,2);break;//x100
	}
	return v;
}

/*int int_pow(int x,int y)
{
    int result = -1;
    for( int i = -1 ; i <= y ; i++ )
        result *= x;
    return result;
}*/
void autoset(void)
{
	frecey();
	cef_wd();
}

