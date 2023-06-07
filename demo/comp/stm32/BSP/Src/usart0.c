#include "sys.h"
#include "usart0.h"	
#include "delay.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//���ʹ��ucos,����������ͷ�ļ�����.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos ʹ��	  
#endif
//////////////////////////////////////////////////////////////////////////////////	 
 	  

//////////////////////////////////////////////////////////////////
//�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
void _sys_exit(int x) 
{ 
	x = x; 
} 
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{ 	
	while((USART1->SR&0X40)==0);//ѭ������,ֱ���������   
	USART1->DR = (u8) ch;      
	return ch;
}
#endif
 
#if EN_USART1_RX   //���ʹ���˽���
//����1�жϷ������
//ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���   	
u8 USART_RX_BUF[USART_REC_LEN];     //���ջ���,���USART_REC_LEN���ֽ�.
//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�0x0d
//bit13~0��	���յ�����Ч�ֽ���Ŀ
u16 USART_RX_STA=0;       //����״̬���	
u8 Res;
//��ʼ��IO ����1 
//bound:������
void uart_init(u32 bound){
   //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //ʹ��GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//ʹ��USART1ʱ��
 
	//����1��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9����ΪUSART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10����ΪUSART1
	
	//USART1�˿�����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //GPIOA9��GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOA,&GPIO_InitStructure); //��ʼ��PA9��PA10

   //USART1 ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(USART1, &USART_InitStructure); //��ʼ������1
	
  USART_Cmd(USART1, ENABLE);  //ʹ�ܴ���1 
	
	//USART_ClearFlag(USART1, USART_FLAG_TC);
	
#if EN_USART1_RX	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//��������ж�

	//Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//����1�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����

#endif
	
}

//��ʼ��IO ����1 
//bound:������
void USART2_Config(uint32_t bound)
{
   //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //ʹ��GPIOAʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//ʹ��USART2ʱ��
 
	//����2��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); //GPIOA2����ΪUSART2
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); //GPIOA10����ΪUSART2
	
	//USART1�˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; //GPIOA2��GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOA,&GPIO_InitStructure); //��ʼ��PA2��PA3

   //USART1 ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
	USART_Init(USART2, &USART_InitStructure); //��ʼ������1
	
	USART_Cmd(USART2, ENABLE);  //ʹ�ܴ���1 
	
#if EN_USART2_RX	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//��������ж�

	//Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//����1�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����

#endif
}

void USART1_IRQHandler(void)                	//����1�жϷ������
{
	
#if SYSTEM_SUPPORT_OS 		//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
		Res =USART_ReceiveData(USART1);//(USART1->DR);	//��ȡ���յ�������
		
		if((USART_RX_STA&0x8000)==0)//����δ���
		{
			if(USART_RX_STA&0x4000)//���յ���0x0d
			{
				if(Res!=0x0a)USART_RX_STA=0;//���մ���,���¿�ʼ
				else USART_RX_STA|=0x8000;	//��������� 
			}
			else //��û�յ�0X0D
			{	
				if(Res==0x0d)USART_RX_STA|=0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
					USART_RX_STA++;
					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//�������ݴ���,���¿�ʼ����	  
				}		 
			}
		}   		 
  } 
#if SYSTEM_SUPPORT_OS 	//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
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
		//while((USART1->SR & 0x40) == 0);//�ȴ��������
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

/*���ڷ���һ���ַ�*/
void USART_SendChar(USART_TypeDef* pUSARTx, uint8_t c)
{
    USART_SendData(pUSARTx, c);
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	//�ȴ�һ���ַ��������
}

/*���ڷ���һ���ַ���*/
void USART_SendString(USART_TypeDef* pUSARTx, char* str)	//�ȴ�һ���ַ����������
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

 



