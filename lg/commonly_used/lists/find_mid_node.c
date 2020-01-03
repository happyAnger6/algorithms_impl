#include <stdio.h>
#include <stdlib.h>

typedef struct list_{
    int data;
    struct list_ *next;
}list, *plist;

plist find_mid_node(plist pHead)
{
    if(NULL == pHead)
        return NULL;

    plist pQuick = pHead, pSlow = pHead;
    int k = 2;
    while(1)
    {
        k = 2;
        while(k)
        {
             pQuick = pQuick->next;
             k--; 
             if(pQuick == NULL)
                break;
        }

        if(k!=0)
            break;
   
        pSlow = pSlow->next; 
    }

    return pSlow;
}
