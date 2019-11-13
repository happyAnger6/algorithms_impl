#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace_space_in_str(char *pcStr)
{
	if(pcStr == NULL)
		return NULL;

	const char *pSpace="%20";
	int spaceLen = strlen(pSpace);
	int len = strlen(pcStr) + 1;

	char *pNew = (char *)malloc(len);
	int newLen = len;
	int i = 0;
	while(*pcStr!='0')
	{
		if(*pcStr!=' ')
		{
			if(i>=newLen)	
			{
				pNew=realloc(pNew,newLen+10);
				newLen+=10;	
			}
			pNew[i]=*pcStr;	
			i++;
		}	
		else
		{
			if(i+spaceLen>=newLen)
			{
				pNew=realloc(pNew,newLen+10);
				newLen+=10;	
			}		
			memcpy(pNew+i,pSpace,spaceLen);
			i+=spaceLen;
		}
		pcStr++;
	}

	pNew[i]=0;	
	return pNew;
}

int main()
{
	char *p = "123 456 789 ";
	
	char *pNew = replace_space_in_str(p);
	printf("[%s]\r\n",pNew);
	return 0;
}
