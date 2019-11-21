#include <stdio.h>
#include <stdlib.h>

#define max_int 0x7fffffff
#define min_int 0x80000000
int reverse_integer(int s)
{
	int symbol = 1;
	if(s<0)
	{
		symbol = -1;
	}

	int res=0;
	while(s%10)
	{
		res=res*10+s%10;
		s=s/10;
	}

	return res*symbol;
}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("usage:%s <intstr>\r\n", argv[0]);
		return -1;
	}

	int input = atoi(argv[1]);
	printf("%d is %d\r\n", input, reverse_integer(input));

	return 0;
}
