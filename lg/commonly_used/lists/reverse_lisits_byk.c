#include <stdio.h>
#include <stdlib.h>

typedef struct list_{
    int data;
    struct list_ *next;
}list, *plist;

int count_left_gt_n(plist pHead, int n)
{
    while(pHead != NULL)
    {
        pHead=pHead->next;
        n--;

        if(n<=0)
            return 1;
    }

    return 0;
}


plist reverse_byk(plist prevHead, plist *pplistCur, int k)
{
    if(k<=0 || !count_left_gt_n(*pplistCur, k))
    {
       prevHead->next = *pplistCur;
       return NULL;  
    }

    plist pNextHead = *pplistCur;
    plist pNext = *pplistCur->next;
    pCur = *pplistCur;
    while(pNext != NULL&&k)
    {
        plist pTmp = pNext->next;
        pNext->next = pCur;
        pCur = pNext;
        pNext = pTmp;
        k--;
    }

    prevHead->next = pCur;
    *pplistCur = pTmp;
    return pNextHead;
}

int reverse_ink(plist pHead, int k)
{
    plist pNewHead = newNode(); 
    plist pNextHead; 
    plist pCur = pHead;
    while(pHead != NULL)
    {
        pNextHead = reverse_byk(pNewHead, &pCur, k);
        if(NULL == pNextHead)
            break;
        pNewHead = pNextHead;
    }
}
