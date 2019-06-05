#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[] = {1,2,2,3,4,5,6,7,8,2,3,4,5,9,11,12,13,14};
	int len = sizeof(a)/sizeof(int);

	int i = 0;
	int *pb = (int *)malloc(len*sizeof(int));

	for(i = 0; i < len; i++)
		pb[i]=0;

	for(i = 0; i < len; i++)
		pb[a[i]]++;

	for(i = 0;i < len; i++)
	{
		if(pb[i]>1)
		{
			printf("[%d]=[%d]\r\n",i,pb[i]);	
		}	
	}


	return 0;
}
