#ifndef _STACK_H
#define _STACK_H

struct Stack;
typedef void* Item;

struct Stack* Stack_init();
Item Stack_pop(struct Stack *stack);
int Stack_push(Item item);

#endif
