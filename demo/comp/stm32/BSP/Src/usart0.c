#include "sys.h"
#include "usart0.h"	
#include "delay.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//如果使用ucos,则包括下面的头文件即可.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos 使用	  
#endif
//////////////////////////////////////////////////////////////////////////////////	 
 	  

//////////////////////////////////////////////////////////////////
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
void _sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{ 	
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
	USART1->DR = (u8) ch;      
	return ch;
}
#endif
 
#if EN_USART1_RX   //如果使能了接收
//串口1中断服务程序
//注意,读取USARTx->SR能避免莫名其妙的错误   	
u8 USART_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
//接收状态
//bit15，	接收完成标志
//bit14，	接收到0x0d
//bit13~0，	接收到的有效字节数目
u16 USART_RX_STA=0;       //接收状态标记	
u8 Res;
//初始化IO 串口1 
//bound:波特率
void uart_init(u32 bound){
   //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //使能GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//使能USART1时钟
 
	//串口1对应引脚复用映射
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9复用为USART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10复用为USART1
	
	//USART1端口配置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //GPIOA9与GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure); //初始化PA9，PA10

   //USART1 初始化设置
	USART_InitStructure.USART_BaudRate = bound;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
  USART_Init(USART1, &USART_InitStructure); //初始化串口1
	
  USART_Cmd(USART1, ENABLE);  //使能串口1 
	
	//USART_ClearFlag(USART1, USART_FLAG_TC);
	
#if EN_USART1_RX	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启相关中断

	//Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器、

#endif
	
}

//初始化IO 串口1 
//bound:波特率
void USART2_Config(uint32_t bound)
{
   //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //使能GPIOA时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//使能USART2时钟
 
	//串口2对应引脚复用映射
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); //GPIOA2复用为USART2
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); //GPIOA10复用为USART2
	
	//USART1端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; //GPIOA2与GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure); //初始化PA2，PA3

   //USART1 初始化设置
	USART_InitStructure.USART_BaudRate = bound;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
	USART_Init(USART2, &USART_InitStructure); //初始化串口1
	
	USART_Cmd(USART2, ENABLE);  //使能串口1 
	
#if EN_USART2_RX	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//开启相关中断

	//Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器、

#endif
}

void USART1_IRQHandler(void)                	//串口1中断服务程序
{
	
#if SYSTEM_SUPPORT_OS 		//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		Res =USART_ReceiveData(USART1);//(USART1->DR);	//读取接收到的数据
		
		if((USART_RX_STA&0x8000)==0)//接收未完成
		{
			if(USART_RX_STA&0x4000)//接收到了0x0d
			{
				if(Res!=0x0a)USART_RX_STA=0;//接收错误,重新开始
				else USART_RX_STA|=0x8000;	//接收完成了 
			}
			else //还没收到0X0D
			{	
				if(Res==0x0d)USART_RX_STA|=0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
					USART_RX_STA++;
					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//接收数据错误,重新开始接收	  
				}		 
			}
		}   		 
  } 
#if SYSTEM_SUPPORT_OS 	//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntExit();  											 
#endif
} 

void USART1_SendStrings(char *str)
{
	//size_t	i;
	int i=0;
	//size_t	retry;
	//for(i = 0; i < size; i++)
	while(str[i] != '\0')
	{
		//while((USART1->SR & 0x40) == 0);//等待发送完毕
		//USART1->DR = (uint8_t)(*(str+i));
		 /* Place your implementation of fputc here */
		/* e.g. write a character to the USART */
		 USART_SendData(USART1, (uint8_t) (*(str+i)));
		/* Loop until the end of transmission */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
		{}
	}
}

void USART1_SendNumber(uint32_t	num, uint8_t jinzhi)
{
	uint8_t t;
	t = num % 10;
	num /=	10;
	if(num != 0)
		
	
		USART1_SendNumber(num, jinzhi);
	if(jinzhi != 16)//not hex
		printf("%d", t);
	else//default:10,decimal
		printf("%x", t);
}

//void HMI_Display_TxtChar(char *name,char *var)
//{
//	USART1_SendStrings(name);
//	USART1_SendStrings("=\"");
//	USART1_SendStrings(var);
//	USART1_SendStrings("\"");
//	//HMI_SendEnd();
//}

/*串口发送一个字符*/
void USART_SendChar(USART_TypeDef* pUSARTx, uint8_t c)
{
    USART_SendData(pUSARTx, c);
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	//等待一个字符发送完毕
}

/*串口发送一个字符串*/
void USART_SendString(USART_TypeDef* pUSARTx, char* str)	//等待一个字符串发送完毕
{
    uint32_t n = 0;
 
    while (*(str + n) != '\0')
    {
        USART_SendChar(pUSARTx, *(str + n));
        n++;
    }
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}

void Send_End()
{
	Delay_us(1000);
	USART_SendChar(USART1,0xFF);
	USART_SendChar(USART1,0xFF);
	USART_SendChar(USART1,0xFF);
}

void HMI_Display_TxtChar(char *name,char *var)
{
	USART_SendString(USART1,name);
	USART_SendString(USART1,"=\"");
	USART_SendString(USART1,var);
	USART_SendString(USART1,"\"");
	Send_End();
}

void HMI_Display_TxtFloat(char *name,float var)
{
	char temp[20];
	char *var_char;
	float temp_var;
	int accuracy = 0;


	temp_var = var;

	if(temp_var < 1.0f)
		;
	else
		while(accuracy < 6)
		{
			temp_var /=10;
			if((int)(temp_var) > 0)
				accuracy ++;
			else
				break;
		}

	var_char = float_to_char(var,temp,7-accuracy);

	USART_SendString(USART1,name);
	USART_SendString(USART1,"=\"");
	USART_SendString(USART1,var_char);
	USART_SendString(USART1,"\"");
	Send_End();
}
void HMI_Wave(char id,char ch,int val)
{
	char temp[20];
	char *val_p;

	val_p = int_to_char(val,temp);

	USART_SendString(USART1,"add ");
	USART_SendChar(USART1,id);
	USART_SendChar(USART1,',');
	USART_SendChar(USART1,ch);
	USART_SendChar(USART1,',');
	USART_SendString(USART1,val_p);

	Send_End();
}
void HMI_Wave_Clear(char objid,char ch)
{
	USART_SendString(USART1,"cle ");
	USART_SendChar(USART1,objid);
	USART_SendChar(USART1,',');
	USART_SendChar(USART1,ch);

	Send_End();
}
char *int_to_char(int data,char store_array[])
{
	char *ret;

	//let the ret point the end of the array
	//and assign it a string end sign
	ret = &store_array[19];
	*(ret--) = '\0';

	if(data == 0)
		*(ret--) = data % 10 + 0x30;

	while(data > 0)
	{
		*(ret--) = data % 10 + 0x30;
		data /= 10;
	}

	//because the upper ret--,there must be a ++ret
	return ++ret;
}

char *float_to_char(float data,char store_array[],int accuracy)
{
	char *ret;
	int temp_data;

	//let the ret point the end of the array
	//and assign it a string end sign
	ret = &store_array[19];
	*(ret--) = '\0';

	temp_data = (int)(data*pow(10,accuracy));

	if(data < 1)
	{
		while(accuracy--)
		{
			*(ret--) = temp_data % 10 + 0x30;
			temp_data /= 10;
		}

		*(ret--) = '.';
		*(ret--) = '0';

		return ++ret;

	}

	while(temp_data > 0)
	{
		//determine whether the decimal point should be added
		if(temp_data == (int)(data))
			*(ret--) = '.';

		*(ret--) = temp_data % 10 + 0x30;
		temp_data /= 10;
	}

	//because the upper ret--,there must be a ++ret
	return ++ret;
}

#endif	

 



