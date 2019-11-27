#ifndef _LIST_H
#define _LIST_H

#include "item.h"

typedef struct node *link;

struct node{
    itemType item;
    link next;
};

void initNodes(int);
void newNode(itemType);
void freeNode(link);
void insertNext(link, link);
link deleteNext(link);
link Next(link);
item Item(link);
#endif
