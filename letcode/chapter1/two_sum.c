#include <stdio.h>
#include <stdlib.h>


int two_sum(int *a, int n, int target, int *x, int *y)
{
	int *sum_d = malloc(sizeof(int)*n);
	int i = 0;
	for(i = 0; i < n; i++)
		sum_d[i] = -1;

	for(i = 0; i < n; i++)
	{
		if(sum_d[target-a[i]]!=-1)
		{
			*x=sum_d[target-a[i]];
			*y=i;
			return 0;
		}
		sum_d[a[i]]=i;
	}

	return -1;
}

int main(int argc, char *argv[])
{
	int a[]={2,3,6,8,7,9};
	int x, y;
	two_sum(a, 10, 9, &x, &y);
	printf("[%d][%d]-[%d][%d]\r\n", x, y, a[x], a[y]);
	return 0;	
}
