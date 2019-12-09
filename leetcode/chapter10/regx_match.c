#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int regx_match(const char *s, const char *regx)
{
	int l1 = strlen(s);
	int l2 = strlen(regx);

	if(l2==0)
	{
		if(l1==0)
			return 1;

		return 0;
	}

	if(l2==1)
	{
		if(l1==l2 && (s[0] == regx[0] || regx[0] == '.'))	
		{
			return 1;
		}
		return 0;
	}

	if(regx[1]=='*')
	{
		while(*s!=0 && (s[0]==regx[0] || regx[0] == '.'))
		{
			if(regx_match(s+1, regx+2))
			{
				return 1;
			}
			
			s+=1;
		}	

		return regx_match(s, regx+2);
	}

	if(*s==0)
		return 0;

	if(s[0]==regx[0] || regx[0] == '.')
	{
		return regx_match(s+1, regx+1);
	}

	return 0;
}

int main(int argc, char *argv[])
{
	if(argc<3)
	{
		printf("usage:%s <str> <regex>\r\n");
		return -1;
	}

	char *s, *regx;
	s = argv[1];
	regx = argv[2];
	printf("%s and %s matched result:[%d]\r\n", s, regx, regx_match(s, regx));

	return 0;
}
