#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str1[] = "helloworld\n";
	char str2[] = "helloworld\n";

	char *pStr1 = "helloworld\n";
	char *pStr2 = "helloworld\n";

	printf("[%d]-[%d]\r\n",str1==str2,pStr1==pStr2);
	return 0;
}
