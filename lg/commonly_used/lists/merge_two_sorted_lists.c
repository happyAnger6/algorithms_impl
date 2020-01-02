#include <stdio.h>
#include <stdlib.h>

typedef struct list_{
    int data;
    struct list_ *next;
}list, *plist;

plist newNode()
{
    plist pTmp = malloc(sizeof(list));
    return pTmp;
}

plist merge_two_sorted_lists(plist p1, plist p2)
{
    plist pHead = newNode();

    while(p1!=NULL || p2 != NULL)
    {
        if(NULL == p1)
        {
            pHead->next = p2;
            break;
        }

        if(NULL == p2)
        {
            pHead->next = p1;
            break;
        }

        if(p1->data < p2->data)
        {
            pHead->next = p1;
            p1=p1->next;
        }
        else
        {
            pHead->next = p2;
            p2 = p2->next;
        }

        pHead=pHead->next;
    }

    plist newList = pHead->next;
    free(pHead);
    return newList;
}
