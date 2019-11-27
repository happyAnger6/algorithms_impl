#include "list.h"

#include <stdio.h>
#include <stdlib.h>

link freelist;

void initNodes(int n)
{
    link freelist = malloc(sizeof(*link)*n);
    int i = 0;
    for(i = 0; i < n-1; i++)
    {
        freelist[i].next = &freelist[i+1]; 
    } 
    freelist[i].next = NULL;
}

link newNode(itemType item)
{
    link x = deleteNext(freelist);
    x->item = item;
    x->next = x;
    return x;  
}

link deleteNext(link l)
{
    t = l->next;
    l->next = t->next;
    return t;
}

void insertNext(link l, link i)
{
    i->next = l->next;
    l->next = i;
}

link Next(link l)
{
    return l->next;
}

item Item(link l)
{
    return l->item;
}
