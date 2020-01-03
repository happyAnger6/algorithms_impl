#include <stdio.h>
#include <stdlib.h>

typedef struct list_{
    int data;
    struct list_ *next;
}list, *plist;

bool is_same(plist p1, plist p2)
{
    return p1 == p2;
}

int move_n(plist *ppNode, int n)
{
    int m = 0;
    plist pNode = *ppNode;
    while(m<n&&pNode!=NULL)
    {
        pNode = pNode->next;
        if(pNode != NULL)
            m++;        
    }
    *ppNode = pNode;
    return m;
}

bool judge_ring(plist pHead)
{
    plist pQuick = pHead, pSlow = pHead;
    while(1)
    {
        move_n(&pQuick, 2);
        if(pQuick == NULL)
           return false;

        move_n(&pSlow, 1);
        if(pSlow == NULL)
           return false;

        if(is_same(pQuick, pSlow))
            return true;
    }        

    return false;
}
