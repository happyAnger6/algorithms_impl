#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int *a, int start, int end)
{
    int guard = a[end];
    int mid = start;
    int i, tmp;
    for(i = start; i < end; i++)
    {
        if(a[i]<=guard)
        {
            tmp = a[mid];
            a[mid] = a[i];
            a[i] = tmp; 
            mid++;
        } 
    }
    tmp = a[mid];
    a[mid]= guard;
    a[end] = tmp;

    return mid;
}

void quick_sort(int *a, int start, int end)
{
    if(start>=end)
        return;

    int mid = partition(a, start, end);
    quick_sort(a, start, mid-1);
    quick_sort(a, mid+1, end);
}


int* get_ary(char *s, int *n)
{
    int len = strlen(s);
    int *a = malloc(sizeof(int)*len);
    int i = 0;
    char c;
    while(c=*s)
    {
        if('0'<=c && c<='9')
        {
            a[i++] = c-'0'; 
        } 
        s++;
    }

    *n = i;
    return a;
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("%s usage:<intstr>\r\n", argv[0]);
        return -1; 
    }

    int n;
    int *a = get_ary(argv[1], &n);
    int i = 0;
    quick_sort(a, 0, n-1);
    for(i = 0; i < n; i++)
    {
        printf("-%d", a[i]); 
    }

    return 0;
}
