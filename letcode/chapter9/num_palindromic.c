#include <stdio.h>
#include <stdlib.h>

int is_parlindromic(int s)
{
	int h, l, w;
	w = 1;
	int tmp = s;
	while(tmp/10!=0)
	{
		tmp=tmp/10;
		w*=10;
	}

	while(w>=10)
	{
		h = s/w;
		l = s%10;
		if(h!=l)
		{
			return 0;
		}
		s=(s%w)/10;
		w=w/100;
	}
	return 1;	
}
int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("usage:%s <num>\r\n");
		return -1;
	}

	printf("[%d] is parlindromic: [%d]\r\n",atoi(argv[1]), is_parlindromic(atoi(argv[1])));
}
