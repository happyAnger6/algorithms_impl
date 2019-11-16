#include <stdio.h>
#include <stdlib.h>

int count(int *ary, int s, int e, int n)
{
	int i = 0, cnt = 0;
	for(i = 0; i < n; i++)
	{
		if(s<=ary[i]&&ary[i]<=e)
			cnt++;
	}
	return cnt;
}

int find_repeated_nochange(int *ary, int n)
{
    int i = 0;
	int start = 0, end = n-1;	
	int mid;
	int range, num;
	while(end>=start)
	{
		mid = start + ((end-start)>>1);
		range = mid - start + 1;
		num = count(ary, start, mid, n);
		if(num>range)
		{
			if(range==1)
				return mid;
			end = mid;
		}	
		else
		{
			start=mid+1;
		}
	}

    return -1;
}

int main()
{
    int a[] = {0,1,3,4,5,7,9,2,4,6};
    printf("[%d]\r\n", find_repeated_nochange(a, 10));

    int i = 0;
    for(i = 0; i < 10; i++)
        printf("[%d]", a[i]);
    return 0;
}
