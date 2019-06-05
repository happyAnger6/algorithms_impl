#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[] = {1,2,2,3,4,5,6,7,8,2,3,4,5,9,11,12,13,14};
	int len = sizeof(a)/sizeof(int);

	int i = 0;
	int tmp;
	for(i = 0; i < len; i++)
	{
		while(1)
		{
			int m = a[i];
			if(i==m)
			{
				break;
			}
			else if(a[m]==m)
			{
				break;
			}
			else
			{
				tmp = a[m];
				a[m] = m;
				a[i] = tmp;	
			}
		}	
	}


	for(i = 0; i < len; i++)
	{
		if(a[i]!=i) printf("[%d]\r\n",a[i]);
	}
	return 0;
}
