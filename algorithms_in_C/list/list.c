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
        freelist[i].next = freelist[i+1]; 
    } 
    freelist[i].next = NULL;
}

void newNode(itemType item)
{
    
}


