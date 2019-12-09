#include <stdio.h>
#include <stdlib.h>

#define min(a,b) ((a)<(b)? (a):(b))

int findKth(int *a, int *b, int na, int nb, int k)
{
	if(k<=0)
		return -1;

	if(na==0)
		return b[k];
	
	if(nb==0)
		return a[k];

	int ma = min(na, k/2) - 1;	
	int mb = k - ma - 2;
	if(a[ma]<b[mb])
	{
			return (&a[ma+1], b, na-ma-1, nb, k-ma-1);
	}
	if(a[ma]>b[mb])	
	{
			return (a, &b[mb+1], na, nb-mb-1, k-mb-1);
	}
	return a[ma];
}

int find_median_in_two_sorted_array(int *a, int *b, int na, int nb)
{
	int n = na + nb;
	if(n%2!=0)
	{
		return findKth(a, b, na, nb, n/2+1);
	}
	else
	{
		return (findKth(a, b, na, nb, n/2) + findKth(a, b, na, nb, n/2+1))/2;
	}
}


int main()
{
	int a[]={1,2,3,4,5,12,13,14};
	int b[]={2,3,4,5,8};

	printf("[%d]\r\n",find_median_in_two_sorted_array(a,b,sizeof(a)/sizeof(int),sizeof(b)/sizeof(int)));
	return 0;
}
