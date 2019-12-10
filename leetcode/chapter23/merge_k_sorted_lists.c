#include <stdio.h>
#include <stdlib.h>

typedef struct list_{
    int data;
    struct list_ *next;
}list;

list* merge_k_sorted_lists(list **ppLists; int k)
{
    int n = k;
    int i = 0;
    while(n>1)
    {
        for(i = 0; i < n/2; i++)
        {
            ppLists[i] = merge_two_sorted_lists(ppList[i], ppList[n-i-1]);         
        } 
        n = (n+1)/2;
    }

    return ppLists[0];
}
