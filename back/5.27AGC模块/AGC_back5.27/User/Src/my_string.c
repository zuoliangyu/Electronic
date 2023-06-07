#include "my_string.h"
#include <string.h>

//static 
void Test(void)
{
		uint8_t *str1 = "hello";
		uint8_t str2[] = "hello";
		BufferCmp(str1, str2, sizeof(str2));
}

TestStatus BufferCmp(const uint8_t* pBuffer1,
											const uint8_t* pBuffer2,
												uint16_t bufferLen)
{
	if((pBuffer1 == NULL) || (pBuffer2 == NULL))
	{
		return FAILED;
	}
		
	while(bufferLen--)
	{
		if(*(pBuffer1) != *(pBuffer2))
		{
				return FAILED;
		}
		pBuffer1++;
		pBuffer2++;
		
		//Ч�ʸ��ߵĴ��� if(*(pBuffer1++) != *(pBuffer2++))
	}
	return PASSED;
}

u8* GetFileName(const char * fpath)
{
		u8 * tmp;
		u16 len = strlen(fpath);
		
		tmp = (u8 *)(fpath+len);
		while(*tmp!= '/')
		{
			tmp--;
		}
		tmp++;
		return tmp;
}












