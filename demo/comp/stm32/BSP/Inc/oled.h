#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"
#include <stdlib.h>
#include "audioplay.h"

//OLED模式设置
//0: 4线串行模式  （模块的BS1，BS2均接GND）
//1: 并行8080模式 （模块的BS1，BS2均接VCC）
#define OLED_MODE 	0 
		    						  
//-----------------OLED端口定义----------------  			
#if OLED_MODE == 0
#define OLED_CS 	PEout(6)
#define OLED_RST  PBout(6)	
#define OLED_RS 	PEout(5)
#define OLED_WR 	PAout(6)		  
#define OLED_RD 	PDout(7)
 
//使用4线串行接口时使用 
#define OLED_SCLK 	PDout(6)
#define OLED_SDIN 	PBout(7)
#endif 
				
#define OLED_CMD  	0		//写命令
#define OLED_DATA 	1		//写数据


typedef struct _oled_ctrl
{
	u16 curMusicDlyCnt;
	u8 is_pmchanged;
} OledCtrl;

extern u8 char_shift;


//OLED控制用函数
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);		   
							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size);	

//OLED gui
void OLED_GuiInit(void);
void OLED_DrawPic(u8 x, u8 y, const u8 *pic, u16 size_arr, u8 size, u8 isHaveHeader);
void OLED_DrawLine(u8 x1, u8 y1, u8 x2, u8 y2, u8 dot);
void OLED_DrawProgressBar(u8 x, u8 y, u8 dx,u8 dy, u8 fill);
void OLED_DisplaySentence(u8 x, u8 y, u16 (*t)[8], u16 (*pSrc)[20], u8 shift);
void OLED_GetPixInfo(u8 *p, u8  size);
void Update_OLED_GUI(u8 *fname);//更新界面
u16 OLED_UpdatePlayTime(u8 x, u8 y,u16 totalTime);//更新播放时间
void OLED_UpdateProcessbar(u8  processCnt);//更新进度条
void OLED_ProgressBarReset(u8 x, u8 y,u8 dx, u8 dy); //复位进度条
void OLED_UpdatePlayMode(PlayMode pm);
void OLED_Welcome(void);
void OLDE_UpdateBatIcon(void);
void AudioSummary(u8 cur, u8 total);


#endif  
	 


