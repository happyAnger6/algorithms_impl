#include <stdio.h>
#include <stdlib.h>

int find_median_in_two_sorted_array(int *a, int *b, int na, int nb)
{
	int n = na + nb;
	if(n%2==0)
	{
		return findKth(a, b, na, nb, n/2);
	}
	else
	{
		return (findKth(a, b, na, nb, n/2) + findKth(a, b, na, nb, n/2+1))/2;
	}
}

int findKth(int *a, int *b, int na, int nb, int k)
{
	if(k<=0)
		return -1;

	if(na==0)
		return b[k];
	
	if(nb==0)
		return a[k];

	int ma = na>>2;	
	int mb = nb>>2;
	if(a[ma]<=b[mb])
	{
		if(ma-na+1>=k)
			return a[k];
		else
			return (&a[ma+1], b, na-ma, nb, k-ma);
	}
	else
	{
		if(mb-nb+1>=k)
			return b[k];
		else
			return (a, &b[mb+1], na, nb-mb, k-mb);
	}
}
