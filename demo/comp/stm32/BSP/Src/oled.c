#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"  	 
#include "delay.h"
#include "oled_gui.h"
#include "gt30l32s4w.h"
#include <stdio.h>
#include <string.h>
#include "wavplay.h"
#include "adc.h"

#include "debug.h"

//OLED的显存
//存放格式如下.
//[0]0 1 2 3 ... 127	
//[1]0 1 2 3 ... 127	
//[2]0 1 2 3 ... 127	
//[3]0 1 2 3 ... 127	
//[4]0 1 2 3 ... 127	
//[5]0 1 2 3 ... 127	
//[6]0 1 2 3 ... 127	
//[7]0 1 2 3 ... 127 		   
u8 OLED_GRAM[128][8];	 
u16 pix[12][20];//最多支持20个字符的歌曲名
u16 t[12][8];

u8 char_shift = 0;
static u32 bat_display_cnt = 0;//电池显示计数器

static u8 MAX(u8 x, u8 y) { return (x>=y ? x : y); }
static u8 MIN(u8 x, u8 y) {	return (x>=y ? y : x); }

static u32 GB2312ToChar(u8 *p, u8 size)
{
	if(size != 2)	return 0;

	if(*p>=0xA1 && *p <= 0xA9 && *(p+1)>=0xA1)
		return 	((*p-0xA1)*94 + (*(p+1)-0xA1))*24+ 0;
	if(*p>=0xB0 && *p <= 0xF7 && *(p+1)>=0xA1)
		return (u32)	((u32)(*p-0xB0)*94 + (u32)(*(p+1)-0xA1) + 846)*24+ 0;	
	
	return 0;
}




//更新显存到LCD		 
void OLED_Refresh_Gram(void)
{
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)OLED_WR_Byte(OLED_GRAM[n][i],OLED_DATA); 
	}   
}
#if OLED_MODE==1	//8080并口
//通过拼凑的方法向OLED输出一个8位数据
//data:要输出的数据
void OLED_Data_Out(u8 data)
{
	u16 dat=data&0X0F;
	GPIOC->ODR&=~(0XF<<6);		//清空6~9
	GPIOC->ODR|=dat<<6;			//D[3:0]-->PC[9:6]
	GPIO_Write(GPIOC,dat<<6);
	PCout(11)=(data>>4)&0X01;	//D4
	PBout(6)=(data>>5)&0X01;	//D5
	PEout(5)=(data>>6)&0X01;	//D6
	PEout(6)=(data>>7)&0X01;	//D7 
} 
//向SSD1306写入一个字节。
//dat:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(u8 dat,u8 cmd)
{
	OLED_Data_Out(dat);	    
 	OLED_RS=cmd;
	OLED_CS=0;	   
	OLED_WR=0;	 
	OLED_WR=1;
	OLED_CS=1;	  
	OLED_RS=1;	 
} 	    	    
#else
//向SSD1306写入一个字节。
//dat:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(u8 dat,u8 cmd)
{	
	u8 i;			  
	OLED_RS=cmd; //写命令 
	OLED_CS=0;		  
	for(i=0;i<8;i++)
	{			  
		OLED_SCLK=0;
		if(dat&0x80)
			OLED_SDIN=1;
		else 
			OLED_SDIN=0;
		OLED_SCLK=1;
		dat<<=1;   
	}				 
	OLED_CS=1;		  
	OLED_RS=1;   	  
} 
#endif
	  	  
//开启OLED显示    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//关闭OLED显示     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;  
	for(i=0;i<8;i++)
		for(n=0;n<128;n++)
			OLED_GRAM[n][i]=0X00;  
	OLED_Refresh_Gram();//更新显示
}
//画点 
//x:0~127
//y:0~63
//t:1 填充 0,清空				   
void OLED_DrawPoint(u8 x,u8 y,u8 t)
{
	u8 pos,bx,temp=0;
	if(x>127||y>63)return;//超出范围了.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)OLED_GRAM[x][pos]|=temp;
	else OLED_GRAM[x][pos]&=~temp;	    
}
//x1,y1,x2,y2 填充区域的对角坐标
//确保x1<=x2;y1<=y2 0<=x1<=127 0<=y1<=63	 	 
//dot:0,清空;1,填充	  
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot)  
{  
	u8 x,y;  
	for(x=x1;x<=x2;x++)
	{
		for(y=y1;y<=y2;y++)OLED_DrawPoint(x,y,dot);
	}													    
	OLED_Refresh_Gram();//更新显示
}
//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//mode:0,反白显示;1,正常显示				 
//size:选择字体 12/16/24
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode)
{      			    
	u8 temp,t,t1;
	u8 y0=y;
	u8 csize=(size/8+((size%8)?1:0))*(size/2);		//得到字体一个字符对应点阵集所占的字节数
	chr=chr-' ';//得到偏移后的值		 
    for(t=0;t<csize;t++)
    {   
		if(size==12)temp=oled_asc2_1206[chr][t]; 	 	//调用1206字体
		else if(size==16)temp=asc2_1608[chr][t];	//调用1608字体
		else if(size==24)temp=asc2_2412[chr][t];	//调用2412字体
		else return;								//没有的字库
        for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==size)
			{
				y=y0;
				x++;
				break;
			}
		}  	 
    }          
}
//m^n函数
u32 mypow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//显示2个数字
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//mode:模式	0,填充模式;1,叠加模式
//num:数值(0~4294967295);	 		  
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size/2)*t,y,' ',size,1);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size/2)*t,y,temp+'0',size,1); 
	}
} 
//显示字符串
//x,y:起点坐标  
//size:字体大小 
//*p:字符串起始地址 
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size)
{	
    while((*p<='~')&&(*p>=' '))//判断是不是非法字符!
    {       
        if(x>(128-(size/2)))
				{
					x=0;
					y+=size;
				}
        if(y>(64-size))
				{
					y=x=0;
					OLED_Clear();
				}
        OLED_ShowChar(x,y,*p,size,1);	 
        x+=size/2;
        p++;
    }  
	
}	

//初始化SSD1306					    
void OLED_Init(void)
{ 	 		 
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOG, ENABLE);//使能PORTA~E,PORTG时钟
  
#if OLED_MODE==1		//使用8080并口模式		
	
	//GPIO初始化设置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7 ;	
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_11;	
	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化	
  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	
	GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_5;	
	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	
	GPIO_Init(GPIOG, &GPIO_InitStructure);//初始化	
 
	
 	OLED_WR=1;
	OLED_RD=1; 
#else					//使用4线SPI 串口模式

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 ;//CS
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;//25MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化
	 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	//RST SDIN
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化		

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	
	GPIO_Init(GPIOD , &GPIO_InitStructure);//初始化RS
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	//RST
	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化
	
	OLED_SDIN=1;
	OLED_SCLK=1;
#endif
	OLED_CS=1;
	OLED_RS=1;	 
	
	OLED_RST=0;
	Delay_ms(100);
	OLED_RST=1; 
					  
	OLED_WR_Byte(0xAE,OLED_CMD); //关闭显示
	OLED_WR_Byte(0xD5,OLED_CMD); //设置时钟分频因子,震荡频率
	OLED_WR_Byte(80,OLED_CMD);   //[3:0],分频因子;[7:4],震荡频率
	OLED_WR_Byte(0xA8,OLED_CMD); //设置驱动路数
	OLED_WR_Byte(0X3F,OLED_CMD); //默认0X3F(1/64) 
	OLED_WR_Byte(0xD3,OLED_CMD); //设置显示偏移
	OLED_WR_Byte(0X00,OLED_CMD); //默认为0

	OLED_WR_Byte(0x40,OLED_CMD); //设置显示开始行 [5:0],行数.
													    
	OLED_WR_Byte(0x8D,OLED_CMD); //电荷泵设置
	OLED_WR_Byte(0x14,OLED_CMD); //bit2，开启/关闭
	OLED_WR_Byte(0x20,OLED_CMD); //设置内存地址模式
	OLED_WR_Byte(0x02,OLED_CMD); //[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
	OLED_WR_Byte(0xA1,OLED_CMD); //段重定义设置,bit0:0,0->0;1,0->127;
	OLED_WR_Byte(0xC0,OLED_CMD); //设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数
	OLED_WR_Byte(0xDA,OLED_CMD); //设置COM硬件引脚配置
	OLED_WR_Byte(0x12,OLED_CMD); //[5:4]配置
		 
	OLED_WR_Byte(0x81,OLED_CMD); //对比度设置
	OLED_WR_Byte(0xEF,OLED_CMD); //1~255;默认0X7F (亮度设置,越大越亮)
	OLED_WR_Byte(0xD9,OLED_CMD); //设置预充电周期
	OLED_WR_Byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_WR_Byte(0xDB,OLED_CMD); //设置VCOMH 电压倍率
	OLED_WR_Byte(0x30,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

	OLED_WR_Byte(0xA4,OLED_CMD); //全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
	OLED_WR_Byte(0xA6,OLED_CMD); //设置显示方式;bit0:1,反相显示;0,正常显示	    						   
	OLED_WR_Byte(0xAF,OLED_CMD); //开启显示	 
	OLED_Clear();
}  

/***********************OLED GUI***************************/

void OLED_GuiInit(void)
{

	OLED_ShowString(0,0, "00:00",12);//time
	OLED_DrawPic(100,0, bat_full, sizeof bat_full, 24, 1);//bat_full
	OLED_DrawLine(0,12, 127, 12,1); //draw line
	OLED_DrawPic(10,15, list_loop, sizeof list_loop, 16,1);//play mode

	OLED_DrawProgressBar(1, 51, 125,3,0);	//56 //初始化进度条
	OLED_DrawPic(2,56, lastSongIcon, sizeof lastSongIcon,16,1);// 上一首
	OLED_DrawPic(27,56, rewindDownIcon, sizeof rewindDownIcon,16,1); //快退
	OLED_DrawPic(54,56, playIcon, sizeof playIcon,16,1);	 //播放
	OLED_DrawPic(81,56, speedIcon, sizeof speedIcon,16,1);	 //快进
	OLED_DrawPic(109,56, nextSong, sizeof nextSong,16,1);	 //下一首
	
	OLED_GetPixInfo( "  欢迎使用", strlen("  欢迎使用"));
	OLED_DisplaySentence(10,25,  t, pix, 0); // 滚动显示当前歌曲

	OLED_Refresh_Gram();//刷新显示
}

void AudioSummary(u8 cur, u8 total)
{
	u8 sum[6];
	
	if(cur >99)	return ;
	
	sum[0] = (cur/10)%10 + 0x30;
	sum[1] = cur%10 + 0x30;
	sum[2] = '/';
	sum[3] = (total/10)%10+ 0x30;
	sum[4] = (total%10)+ 0x30;
	sum[5] = '\0';
	
	OLED_ShowString(90,15, sum, 12);// 统计歌曲
}

void OLED_DrawPic(u8 x, u8 y, const u8 *pic, u16 size_arr, u8 size, u8 isHaveHeader)
{
	u8 i, j, temp;
	u8 x0=x;
	
	//printf("func oled sizeof pic is %d\r\n", sizeof(pic));
	for(i=0 ;i<size_arr; i++)
	{
		temp = *(pic+i);
		for(j =0; j<8; j++)
		{
			if(temp&0x80)
				OLED_DrawPoint(x,y,1);
			else 
				OLED_DrawPoint(x,y,0);
			temp<<=1;
			x++;
			if(x-x0 ==size)
			{	
				y++;
				x=x0;
			}
		}		
	}
}

void OLED_DrawLine(u8 x1, u8 y1, u8 x2, u8 y2, u8 dot)
{
	u8 cnt =0;
	if(x1 == x2)
	{
		for(cnt=MIN(y1,y2); cnt <MAX(y1,y2); cnt++)
			OLED_DrawPoint(x1, cnt, dot);	
	}
	if(y1 == y2)
	{
		for(cnt=MIN(x1,x2); cnt <MAX(x1,x2); cnt++)
			OLED_DrawPoint(cnt, y1, dot);	
	}
	OLED_Refresh_Gram();
}

void OLED_DrawProgressBar(u8 x, u8 y, u8 dx,u8 dy, u8 fill)
{
 	u8 i;
	if(fill>127)
		return;
	if(x+dx<=128 && y+dy<= 64)
	{
	 	 OLED_DrawLine(x, 	y, 		x+dx, 	y, 		1);
		 OLED_DrawLine(x, 	y+dy, 	x+dx, 	y+dy, 	1);
		 OLED_DrawLine(x,	y, 		x, 		y+dy, 	1);
		 OLED_DrawLine(x+dx,y, 		x+dx, 	y+dy, 	1);
		
		 for(i=y+1; i<y+dy; i++)
				OLED_DrawLine(x, 	i, 		x+fill, 	i, 	1);
	}
	
}


void OLED_GetPixInfo(u8 *p, u8  size)
{
	u8 i,j;

	u8 cnt;
	u8 chr;

	u32 res;

	u8 real=0;
	u8 sw=0;
	u8 index =0;
	u8 flag=0;
	u8 index1=0;

	//得到字符数，一个汉字两字节GB2312
	//charCnt = SummaryChars(p, size);

	for(i = 0; i< 12; i++)
		for(j =0; j<20; j++)
			pix[i][j] = 0x00;

	for(cnt =0; cnt < size; )
	{
		//printf("size is %d; cnt is %d ",size, cnt);
		if(*(p+cnt) >= 0xA1)
		{
		 	res =  GB2312ToChar((p+cnt),2);

			//复位数字字符数组
			for(i =0; i < 24; i++)
				pixel_12_12[i] = 0x00;

			//printf("res is %ld. 0x%x 0x%x ", res,  *(p+cnt), *(p+cnt+1));
			GT30L32s4w_Read(0x03, res, pixel_12_12);
	
		//	printf("\r\n\r\n");
		//	for(i =0; i < 24; i++)
		//		printf("0x%x ",pixel_12_12[i]);
		//	printf("\r\n\r\n");

			for(i=0; i<12; i++)
			{
				//t[i] = *(pixel_12_12+2*i)<<8 + *(pixel_12_12+2*i+1); // t[i] = 0
				pix[i][real] = (u16) (*(pixel_12_12+2*i)<<8) |  (u16)*(pixel_12_12+2*i+1); // well
				//printf("0x%x ", pix[i][real]);
			}
			real++;	
			cnt +=2;
			printf("");
			//printf("hanzi\r\n");
		}
		else if(*(p+cnt) < 0x7f)
		{ 	
		//	| |	|
		//	| |	|
		//	|	|
		//	| |	|
		//	  |
		//	| |	|
		//	| |	|
			//asscii虽然按照12*12 其实只用了12*8
			//而且按纵向排列
		//	printf("char");
			chr = *(p+cnt);
			chr -= ' ';
			for(i=0; i<12; i++, flag++)
		    {   
				sw = oled_asc2_1206[chr][i];
				for(j=0; j<8; j++, index++)
				{
				 	if(sw & 0x80)
					{
						//printf("%d,%d: 1 \r\n",index, 15-index1);
						pix[6][real] |= 1<<(15-index1);	   	
					}
					else
					{
						//printf("0");
						pix[index][real] &= ~(1<<(15-index1));
					}
					sw <<= 1;

					if(index && index%12==0)
					{
					//printf();
						index = 0;
					}
					
				}
				index1++;
				if(flag >=2)
				{
					//index1++;
					flag =0;
				}
				//printf("0x%x ",oled_asc2_1206[chr][j]);
				//printf("0x%x \r\n", pix[j][real]);
			}
			real++;
			cnt++;
		}
	}
			
}

void OLED_DisplaySentence(u8 x, u8 y, u16 (*t)[8], u16 (*pSrc)[20], u8 shift)
{
	u8 i,j,k;
	u16 temp;
	const u8 xx = x;
	const u8 yy = y;
	u8 x0 = x;
	u8 y0 = y;

	for(i=0; i<12;i++)
		for(j=0; j<8; j++)
		{
			t[i][j]= pix[i][j+shift];	 	
		}
    
	//deal with scroll
	for(i=0 ;i<8; i++)
	{
		for(j=0; j<12; j++)
		{
			temp = t[j][i];
			for(k =0; k<12; k++)
			{
				if(temp&0x8000)
				{
					OLED_DrawPoint(x,y,1);
				}
				else 
				{
					OLED_DrawPoint(x,y,0);
				}
				temp<<=1;
				x++;
			}
			//printf("\r\n");
			y++;
			x=x0;	
		}
		//如果是字符，则可以写成x += 8;
		x += 12;
		x0 += 12;
		y = y0;
	}
	//初始位置复位	
	x = x0 = xx;
	y = y0 = yy;   
	
}



void Update_OLED_GUI(u8* fname)
{
	u8 progressBarCnt = 0;
	
	progressBarCnt = (u8)((1.0*wavctrl.cursec/wavctrl.totsec)*128);
	OLED_UpdateProcessbar(progressBarCnt);//更新播放进度条
	
	OLED_GetPixInfo(fname, strlen((const char *)fname)-4);
	OLED_DisplaySentence(10, 25, t, pix, char_shift++);//滚动显示歌曲名
	if(char_shift >= 8)
			char_shift = 0;
	
	OLED_UpdatePlayTime(5, 39, wavctrl.cursec);//更新播放时间
	
	if(audioDev.is_pmchanged == 1)
	{
		OLED_UpdatePlayMode(audioDev.playMode);//更新播放模式
		audioDev.is_pmchanged = 0;
	}	
	if(bat_display_cnt++ >10)
	{
		OLDE_UpdateBatIcon();//检测电池电量
		bat_display_cnt = 0;
	}
	
	OLED_Refresh_Gram();//刷新显示
	
	#if DBG
		//printf("%s\r\n", fname);
		//printf("pBarCnt:%d\r\n", progressBarCnt);
	#endif
	
}

void OLED_UpdatePlayMode(PlayMode pm)
{
	switch(pm)
	{
		case LIST_PLAY:
			OLED_DrawPic(10,15, list_play, sizeof list_play, 16,1);//play mode
			break;
		case LIST_LOOP:
			OLED_DrawPic(10,15, list_loop, sizeof list_loop, 16,1);//play mode
			break;
		case SINGLE_MUSIC:
			OLED_DrawPic(10,15, single_music, sizeof single_music, 16,1);//play mode
			break;
		case SINGLE_LOOP:
			OLED_DrawPic(10,15, single_loop, sizeof single_loop, 16,1);//play mode
			break;
		case RANDOM_PLAY:
			OLED_DrawPic(10,15, random_play, sizeof random_play, 16,1);//play mode
			break;
		default:
			#if DBG
			while(1)
				printf("%d 播放模式出现错误\r\n", audioDev.playMode);
			#endif
			break;
	}
}

u16 
OLED_UpdatePlayTime(u8 x, u8 y,u16 totalTime)
{
	u16 res;
	u8 t[6]= "";
	u8 s0,s1,s3,s4;
	u16 tmp;
	
	tmp = totalTime/60;
	if(tmp>9 && tmp < 100)
	{//over 100minutes not supported
		s0 = tmp/10;
		s1 = tmp %10;
	}
	else
	{
		s0 = 0;
		s1 = tmp %10;
	}
	
	tmp = totalTime-(u8)(totalTime/60) * 60;
	if(tmp>9)
	{
		s3 = tmp/10;
		s4 = tmp%10;
	}
	else
	{
		s3 = 0;
		s4 = tmp%10;
	}

	t[0] = s0 + 0x30;
	t[1] = s1 + 0x30;
	t[2] = ':';
	t[3] = s3 + 0x30;
	t[4] = s4 + 0x30;
	t[5] = '\0';
	
	#if DBG
	//printf("total time %d:%s\r\n", totalTime, t);
	#endif
	
	OLED_ShowString(x,y, t, 12);//time
	return res;				
}

void
OLED_ClearSection(u8 x, u8 y, u8 dx, u8 dy)
{
	u8 i;
	for(i =0; i<dx; i++)
	{
		OLED_DrawLine(x,y, x, y+dy, 0);
		//y++;
		x++;
	}		
  	OLED_Refresh_Gram();

}

void
OLED_ProgressBarReset(u8 x, u8 y,u8 dx, u8 dy)
{
	u8 i;
	for(i=y+1; i<y+dy; i++)
		OLED_DrawLine(x, 	i, 		x+dx, 	i, 	0);		
}

void OLED_UpdateProcessbar(u8  processCnt)
{
	OLED_DrawProgressBar(1, 51, 126,3,processCnt);	//56
		
	if(processCnt>=128)
	{
	  OLED_ProgressBarReset(1,51,126,3);
	  processCnt=0;
		OLED_ClearSection(20,25,90,12);
	} 
}

void OLED_Welcome(void)
{
	//OLED_GetPixInfo( "欢迎使用STM32 WAV", strlen("欢迎使用STM32 WAV"));

	//OLED_Refresh_Gram();//刷新显示
}


static void OLDE_UpdateBatIcon(void)
{
	u16 tmp = 0;
	u16 v1000 = 0;
	
	tmp = Get_Adc_Average(ADC_Channel_5,1);
	
	v1000 = (u16)(1000*(3.3f * tmp / 4096));
	
	#if DBG
	printf("当前电压ADC value:%d\r\n", tmp);
	#endif
	
	//(100,0)电池图标的起始坐标
	if(v1000 > 3000)
	{
		OLED_DrawPic(100,0, bat_full, sizeof bat_full, 24, 1);//bat_full
	}
	else if(v1000>2700)
	{
		OLED_DrawPic(100,0, bat_4, sizeof bat_4, 24, 1);//bat_4
	}
	else if(v1000>2500)
	{
		OLED_DrawPic(100,0, bat_3, sizeof bat_3, 24, 1);//bat_3
	}
	else if(v1000>2200)
	{
		OLED_DrawPic(100,0, bat_2, sizeof bat_2, 24, 1);//bat_2
	}
	else if(v1000>2000)
	{
		OLED_DrawPic(100,0, bat_1, sizeof bat_1, 24, 1);//bat_1
	}
	else if(v1000>1800)
	{
		OLED_DrawPic(100,0, bat_0, sizeof bat_0, 24, 1);//bat_0
	}
	else
	{
		OLED_DrawPic(100,0, bat_0, sizeof bat_0, 24, 1);//else
	}
	
}




