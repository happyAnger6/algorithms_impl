#include <stdio.h>
#include <stdlib.h>

typedef struct list_{
    int data;
    struct list_ *next;
}list, *plist;


plist tail_knode(plist pHead, int k)
{
    if(0==k || NULL == pHead)
        return NULL;

    plist pFront, pTail;
    pFront = pTail = pHead;
    k--;
    while(k>0&&pTail!=NULL)
    {
        pTail = pTail->next; 
        k--;
    }

    if(NULL == pTail)
        return NULL;

    while(pTail->next!=NULL)
    {
        pFront = pFront->next;
        pTail = pTail->next; 
    }

    return pFront;
}


