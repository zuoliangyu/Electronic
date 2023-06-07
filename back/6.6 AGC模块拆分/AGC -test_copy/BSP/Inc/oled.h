#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"
#include <stdlib.h>
#include "audioplay.h"

//OLEDģʽ����
//0: 4�ߴ���ģʽ  ��ģ���BS1��BS2����GND��
//1: ����8080ģʽ ��ģ���BS1��BS2����VCC��
#define OLED_MODE 	0 
		    						  
//-----------------OLED�˿ڶ���----------------  			
#if OLED_MODE == 0
#define OLED_CS 	PEout(6)
#define OLED_RST  PBout(6)	
#define OLED_RS 	PEout(5)
#define OLED_WR 	PAout(6)		  
#define OLED_RD 	PDout(7)
 
//ʹ��4�ߴ��нӿ�ʱʹ�� 
#define OLED_SCLK 	PDout(6)
#define OLED_SDIN 	PBout(7)
#endif 
				
#define OLED_CMD  	0		//д����
#define OLED_DATA 	1		//д����


typedef struct _oled_ctrl
{
	u16 curMusicDlyCnt;
	u8 is_pmchanged;
} OledCtrl;

extern u8 char_shift;


//OLED�����ú���
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
void Update_OLED_GUI(u8 *fname);//���½���
u16 OLED_UpdatePlayTime(u8 x, u8 y,u16 totalTime);//���²���ʱ��
void OLED_UpdateProcessbar(u8  processCnt);//���½�����
void OLED_ProgressBarReset(u8 x, u8 y,u8 dx, u8 dy); //��λ������
void OLED_UpdatePlayMode(PlayMode pm);
void OLED_Welcome(void);
void OLDE_UpdateBatIcon(void);
void AudioSummary(u8 cur, u8 total);


#endif  
	 


