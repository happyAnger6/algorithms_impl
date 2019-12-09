#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int myatoi(const char *s)
{
	int symbol = 1;
	if(NULL == s || *s==0)
		return 0;

	if(*s=='-')
	{
		symbol = -1;	
		s++;
	}

	char c;
	int n = 0;
	int ret;
	while((c=*s++)!=0)
	{
		if('0'<=c && c<='9')
		{
			n = c - '0';
			if(ret > (INT_MAX - n)/10)
			{
				return symbol==-1? INT_MIN: INT_MAX;
			}

			ret=ret*10+n;
		}	
		else
		{
			return 0;
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("usage:%s <str>\r\n");
		return -1;
	}
	printf("[%d]\r\n", myatoi(argv[1]));
	return 0;
}
