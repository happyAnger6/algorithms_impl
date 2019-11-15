#include <stdio.h>
#include <stdlib.h>


int find_repeated(int *ary, int n)
{
    int i = 0;
    int k, tmp;
    for(i = 0; i < n; i++)
    {
        while(1)
        {
            k = ary[i];
            if(k==i) break;

            if(ary[k]==k)
                return k;
            tmp = ary[k];
            ary[k]=k;
            ary[i]=tmp;
        }
    }

    return -1;
}

int main()
{
    int a[] = {0,1,3,4,5,7,9,2,4,6};
    printf("[%d]\r\n", find_repeated(a, 10));

    int i = 0;
    for(i = 0; i < 10; i++)
        printf("[%d]", a[i]);
    return 0;
}
