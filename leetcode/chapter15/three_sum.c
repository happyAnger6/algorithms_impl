#include <stdio.h>
#include <stdlib.h>

int sorted(int *a)
{

}

int** three_sum(int *a, int n, int target)
{
    int i;
    int e, sum;
    int ret[3] = {0};
    int k, j;
    for(i = 0; i < n-2; i++)
    {
        k = 0;
        if(i>0 && a[i]==a[i-1])
            continue;

        e = a[i];
        if(e > target)
            continue;

        ret[0] = e;
        sum = target - e;

        j = n - 1;
        i+=1;
        while(i<=j)
        {
            if(a[i]+a[j] == sum)
            {
                ret[1] = a[i];
                ret[2] = a[j];
                i++;
                j--;
                while(i<j&&a[i]==a[i-1]) i++;
                while(j>i&&a[j]==a[j+1]) j--;
            }
            else if(a[i] + a[j] > sum)
            {
                j--; 
            }     
            else
            {
                i++ ;
            }
        }
    }  
}

int main(int argc, char *argv[])
{
    int (*pa)[4];

    return 0;
}
