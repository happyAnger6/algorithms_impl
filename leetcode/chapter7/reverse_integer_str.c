#include <stdio.h>
#include <stdlib.h>

#define max_int 0x7fffffff
#define min_int 0x80000000
int reverse_integer(const char *s)
{
	int symbol = 1;
	int result = 0;
	int weight = 1;
	char c;
	while(c=*s++)
	{
		if(c=='-')
		{
			symbol*=-1;
		}
		else if(c=='+')
		{
			continue;
		}
		else
		{
			result=result+(c-'0')*weight;
			weight*=10;
		}
	}

	return result*symbol;
}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("usage:%s <intstr>\r\n", argv[0]);
		return -1;
	}

	printf("%s is %d\r\n", argv[1], reverse_integer(argv[1]));

	return 0;
}
