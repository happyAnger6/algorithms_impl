#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int genData()
{
    return rand()%1000;
}


int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <n>\r\n", argv[0]);
        return -1; 
    }

    LIST_HEAD(head);
    LIST_HEAD(head1);
    int i = 0;
    int n = atoi(argv[1]);
    for(i = 0; i < n; i++)
    {
        list_add(&head, genData()); 
    }

    list_traverse(&head);
    ListNode **ppPos = &(head1->pNext);
    ListNode *pHead = &head;
    ListNode *pHead1 = &head1;
    ListNode *pCur = pHead->pNext;
    ListNode *pTmp;
    while(pCur != NULL)
    {
        while(pHead1->pNext != NULL)
        {
            ppPost = &(pHead1->pNext);
            if(pHead1->pNext->iData > pCur->iData)
            {
                break; 
            } 
            pHead1 = pHead1->pNext;
        }
        pTmp = pCur->pNext;
        pCur->pNext = (*ppPost)->pNext;
        *ppPost = pCur;
        pCur = pTmp;
    }

    list_traverse(&head1);
    return 0;
}
