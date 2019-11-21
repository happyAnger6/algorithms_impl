#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* add_comma(const char *s)
{
	int n = strlen(s);
	int nc = (n-1)/3;
	int newn = n+nc;
	char *tmp = malloc(newn+1);
	char *d = tmp;
	int r = n%3;
	if(r==0)
		r=3;

	while(n>0)
	{	
		while(r>0)
		{		
			*d++=*s++;
			r--;
			n--;	
		}

		if(n>0)
		{
			*d++=',';
			*d++=*s++;
			*d++=*s++;
			*d++=*s++;
			n-=3;
		}
	}
	*d=0;
	return tmp;
}
int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("usage:%s <str>\r\n", argv[0]);
		return -1;
	}

	printf("%s\r\n", add_comma(argv[1]));
	return 0;
}
