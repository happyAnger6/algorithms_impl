#include <stdio.h>
#include <stdlib.h>

struct list_{
    int data;
    struct list_ *next;
}list;

list* merge_two_sorted_lists(list *l1, list *l2)
{
    list dummy;
    dummy.data = -1;
    dummy.next = NULL;
    list *cur = &dummy;

    while(l1&&l2)
    {
        if(l1->data<l2->data)
        {
            cur->next = l1;
            l1 = l1->next; 
        } 
        else
        {
            cur->next = l2;
            l2 = l2->next; 
        }

        cur = cur->next;
    }

    cur->next = l1? l1 : l2;
    return dummy.next;
}
