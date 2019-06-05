#include <stdio.h>
#include <stdlib.h>


int quick_sort(int a[], int low, int high)
{
        if(low >= high) return;

        int mid = partition(a, low, high);
        quick_sort(a, low, mid-1);
        quick_sort(a, mid+1, high);
}

int partition(int a[], int low, int high)
{
    int i = low - 1;
    int j = low;
    int base = a[high];
    int tmp = 0;
    while(j < high)
    {
        if(a[j] < base)
        {
                i++;
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
        } 
        j++;
    }
    i++;
    tmp=a[i];
    a[i]=base;
    a[high]=tmp;

   return i; 
}

int main()
{
    int a[] = {8,3,2,4,5,6,7,10,12,13,1};
    int len = sizeof(a)/sizeof(int);
    quick_sort(a,0,len-1);
    int i = 0;
    for(i = 0; i < len; i++)
        printf("[%d]=[%d]\r\n",i,a[i]);
    return 0;
}
