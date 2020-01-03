typedef struct list_{
    int data;
    struct list_ *next;
}list, *plist;

plist reverse_byk(plist pHead, int k)
{
    if(NULL == pHead)
        return NULL;

    plist pNextStarted = pHead;
    int n = k;
    while(--n&&(pNextStarted!=NULL))
    {
        pNextStarted = pNextStarted->next;
    }

    if(n==0)
    {
        plist pNextHead = reverse_byk(pNextStarted, k);
        plist pCur = pHead;
        plist pNext = pHead->next;
        while(pNext!=NULL&&--k)
        {
            plist pTmp = pNext->next;
            pNext->next = pCur;
            pCur = pNext;
            pNext = pTmp;
        }
        pHead->next = pNextHead;
        return pCur;
    }

    return pHead;
}
