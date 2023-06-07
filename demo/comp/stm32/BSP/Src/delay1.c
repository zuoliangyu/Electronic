#include "delay1.h"
#include "sys.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//Èç¹ûÊ¹ÓÃucos,Ôò°üÀ¨ÏÂÃæµÄÍ·ÎÄ¼ş¼´¿É.
#if SYSTEM_SUPPORT_UCOS
#include "includes.h"					//ucos Ê¹ÓÃ	  
#endif
 
static uint8_t  fac_us=0;//usÑÓÊ±±¶³ËÊı			   
static u16 fac_ms=0;//msÑÓÊ±±¶³ËÊı,ÔÚucosÏÂ,´ú±íÃ¿¸ö½ÚÅÄµÄmsÊı

#ifdef OS_CRITICAL_METHOD 	//Èç¹ûOS_CRITICAL_METHOD¶¨ÒåÁË,ËµÃ÷Ê¹ÓÃucosIIÁË.
//systickÖĞ¶Ï·şÎñº¯Êı,Ê¹ÓÃucosÊ±ÓÃµ½
void SysTick_Handler(void)
{				   
	OSIntEnter();		//½øÈëÖĞ¶Ï
    OSTimeTick();       //µ÷ÓÃucosµÄÊ±ÖÓ·şÎñ³ÌĞò               
    OSIntExit();        //´¥·¢ÈÎÎñÇĞ»»ÈíÖĞ¶Ï
}
#endif
			   
//³õÊ¼»¯ÑÓ³Ùº¯Êı
//µ±Ê¹ÓÃucosµÄÊ±ºò,´Ëº¯Êı»á³õÊ¼»¯ucosµÄÊ±ÖÓ½ÚÅÄ
//SYSTICKµÄÊ±ÖÓ¹Ì¶¨ÎªHCLKÊ±ÖÓµÄ1/8
//SYSCLK:ÏµÍ³Ê±ÖÓ
void Delay_Config(uint8_t SYSCLK)
{
#ifdef OS_CRITICAL_METHOD 	//Èç¹ûOS_CRITICAL_METHOD¶¨ÒåÁË,ËµÃ÷Ê¹ÓÃucosIIÁË.
	uint32_t reload;
#endif
//ÕâÀïÊÇÔÚÃ»ÓĞÊ¹ÓÃPLL±¶ÆµÇé¿öÏÂ½øĞĞµÄÉèÖÃ¡£
 	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us=SYSCLK/8;		//²»ÂÛÊÇ·ñÊ¹ÓÃucos,fac_us¶¼ĞèÒªÊ¹ÓÃ
	    
#ifdef OS_CRITICAL_METHOD 	//Èç¹ûOS_CRITICAL_METHOD¶¨ÒåÁË,ËµÃ÷Ê¹ÓÃucosIIÁË.
	reload=SYSCLK/8;		//Ã¿ÃëÖÓµÄ¼ÆÊı´ÎÊı µ¥Î»ÎªK	   
	reload*=1000000/OS_TICKS_PER_SEC;//¸ù¾İOS_TICKS_PER_SECÉè¶¨Òç³öÊ±¼ä
							//reloadÎª24Î»¼Ä´æÆ÷,×î´óÖµ:16777216,ÔÚ168MÏÂ,Ô¼ºÏ0.7989s×óÓÒ	
	fac_ms=1000/OS_TICKS_PER_SEC;//´ú±íucos¿ÉÒÔÑÓÊ±µÄ×îÉÙµ¥Î»	   
	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;   	//¿ªÆôSYSTICKÖĞ¶Ï
	SysTick->LOAD=reload; 	//Ã¿1/OS_TICKS_PER_SECÃëÖĞ¶ÏÒ»´Î	
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;   	//¿ªÆôSYSTICK
#else
	fac_ms=(u16)fac_us*1000;//·ÇucosÏÂ,´ú±íÃ¿¸ömsĞèÒªµÄsystickÊ±ÖÓÊı   
#endif
}								    

#ifdef OS_CRITICAL_METHOD 	//Èç¹ûOS_CRITICAL_METHOD¶¨ÒåÁË,ËµÃ÷Ê¹ÓÃucosIIÁË.
//ÑÓÊ±nus
//nus:ÒªÑÓÊ±µÄusÊı.		    								   
void Delay_us(uint32_t nus)
{		
	uint32_t ticks;
	uint32_t told,tnow,tcnt=0;
	uint32_t reload=SysTick->LOAD;	//LOADµÄÖµ	    	 
	ticks=nus*fac_us; 			//ĞèÒªµÄ½ÚÅÄÊı	  		 
	tcnt=0;
	OSSchedLock();				//×èÖ¹ucosµ÷¶È£¬·ÀÖ¹´ò¶ÏusÑÓÊ±
	told=SysTick->VAL;        	//¸Õ½øÈëÊ±µÄ¼ÆÊıÆ÷Öµ
	while(1)
	{
		tnow=SysTick->VAL;	
		if(tnow!=told)
		{	    
			if(tnow<told)tcnt+=told-tnow;//ÕâÀï×¢ÒâÒ»ÏÂSYSTICKÊÇÒ»¸öµİ¼õµÄ¼ÆÊıÆ÷¾Í¿ÉÒÔÁË.
			else tcnt+=reload-tnow+told;	    
			told=tnow;
			if(tcnt>=ticks)break;//Ê±¼ä³¬¹ı/µÈÓÚÒªÑÓ³ÙµÄÊ±¼ä,ÔòÍË³ö.
		}  
	};
	OSSchedUnlock();			//¿ªÆôucosµ÷¶È 									    
}
//ÑÓÊ±nms
//nms:ÒªÑÓÊ±µÄmsÊı
void Delay_ms(u16 nms)
{	
		if(OSRunning==OS_TRUE&&OSLockNesting==0)//Èç¹ûosÒÑ¾­ÔÚÅÜÁË	   
	{		  
		if(nms>=fac_ms)//ÑÓÊ±µÄÊ±¼ä´óÓÚucosµÄ×îÉÙÊ±¼äÖÜÆÚ 
		{
   			OSTimeDly(nms/fac_ms);	//ucosÑÓÊ±
		}
		nms%=fac_ms;				//ucosÒÑ¾­ÎŞ·¨Ìá¹ÕâÃ´Ğ¡µÄÑÓÊ±ÁË,²ÉÓÃÆÕÍ¨·½Ê½ÑÓÊ±    
	}
	Delay_us((uint32_t)(nms*1000));		//ÆÕÍ¨·½Ê½ÑÓÊ± 
}
#else  //²»ÓÃucosÊ±
//ÑÓÊ±nus
//nusÎªÒªÑÓÊ±µÄusÊı.	
//×¢Òâ:nusµÄÖµ,²»Òª´óÓÚ798915us
void Delay_us(uint32_t nus)
{		
	uint32_t temp;	    	 
	SysTick->LOAD=nus*fac_us; //Ê±¼ä¼ÓÔØ	  		 
	SysTick->VAL=0x00;        //Çå¿Õ¼ÆÊıÆ÷
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //¿ªÊ¼µ¹Êı 
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));//µÈ´ıÊ±¼äµ½´ï   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //¹Ø±Õ¼ÆÊıÆ÷
	SysTick->VAL =0X00;       //Çå¿Õ¼ÆÊıÆ÷	 
}

//ÑÓÊ±nms
//×¢ÒânmsµÄ·¶Î§
//SysTick->LOADÎª24Î»¼Ä´æÆ÷,ËùÒÔ,×î´óÑÓÊ±Îª:
//nms<=0xffffff*8*1000/SYSCLK
//SYSCLKµ¥Î»ÎªHz,nmsµ¥Î»Îªms
//¶Ô168MÌõ¼şÏÂ,nms<=798ms 
void Delay_xms(u16 nms)
{	 		  	  
	uint32_t temp;		   
	SysTick->LOAD=(uint32_t)nms*fac_ms;//Ê±¼ä¼ÓÔØ(SysTick->LOADÎª24bit)
	SysTick->VAL =0x00;           //Çå¿Õ¼ÆÊıÆ÷
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //¿ªÊ¼µ¹Êı  
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));//µÈ´ıÊ±¼äµ½´ï   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //¹Ø±Õ¼ÆÊıÆ÷
	SysTick->VAL =0X00;       //Çå¿Õ¼ÆÊıÆ÷	  	    
} 

//ÑÓÊ±nms 
//nms:0~65535
void Delay_ms(u16 nms)
{	 	 
	uint8_t repeat=nms/540;	//ÕâÀïÓÃ540,ÊÇ¿¼ÂÇµ½Ä³Ğ¿Í»§¿ÉÄÜ³¬ÆµÊ¹ÓÃ,
						//±ÈÈç³¬Æµµ½248MµÄÊ±ºò,delay_xms×î´óÖ»ÄÜÑÓÊ±541ms×óÓÒÁË
	u16 remain=nms%540;
	while(repeat)
	{
		Delay_xms(540);
		repeat--;
	}
	if(remain)
		Delay_xms(remain);
	
} 

#endif

void Delay(uint32_t time)
{
	while(time--);
}