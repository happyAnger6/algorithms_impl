#ifndef _LIST_H
#define _LIST_H

typedef struct _listNode{
    int iData;
    struct _listNode *pNext;
}ListNode;

#define LIST_HEAD(head) ListNode head = { .iData = -1,\
       .pNext = NULL,\
}

static inline void list_add(ListNode *head, int data)
{
    ListNode *pNode = malloc(sizeof(ListNode));
    pNode->iData = data;
    pNode->pNext = head->pNext;
    head->pNext = pNode;
}

static inline void list_traverse(ListNode *head)
{
    while(head->pNext != NULL)
    {
        printf("-%d", head->pNext->iData);
        head = head->pNext; 
    }
}
#endif
