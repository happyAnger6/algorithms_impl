#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace_space_in_str(char *pcStr)
{
	if(pcStr == NULL)
		return NULL;

	const char *pSpace="%20";
	int spaceLen = strlen(pSpace);

	int sc = 0, i = 0;
	int len = strlen(pcStr);
	for(i = 0; i < len; i++)
	{
		if(pcStr[i] == ' ') sc++;	
	}

	printf("[%d]\r\n",sc);
	if(0==sc) return pcStr;
	
	int mlen = 0;
	int j = len;
	for(;j>=0;j--)
	{
		if(pcStr[j]!=' ')
		{
			mlen++;	
		}
		else
		{
			memcpy(pcStr+j+1+sc*(spaceLen-1),pcStr+j+1,mlen);
			mlen=0;
			memcpy(pcStr+j+1+sc*(spaceLen-1)-spaceLen,pSpace,spaceLen);
			sc--;		
		}

		if(sc==0) break;
	}
	return pcStr;
}

int main()
{
	char p[30] = "123 456 789 ";
	
	char *pNew = replace_space_in_str(p);
	printf("[%s]\r\n",pNew);
	return 0;
}
