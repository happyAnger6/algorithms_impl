#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct Stack{
	Item *datas;
	int n;
}*PStack;

#define STACK_INIT_SIZE 8

PStack Stack_init()
{
	PStack pStack = (PStack)malloc(sizeof(struct Stack));
	if(NULL == pStack)
	{
		return NULL;
	}
	pStack->datas = (void *)malloc(sizeof(Item)*STACK_INIT_SIZE);
	if(pStack->datas == NULL)
	{
		free(pStack);
		return NULL;
	}
	pStack->n = STACK_INIT_SIZE;
	return pStack;
}

Item Stack_pop(struct Stack *stack)
{
	PStack pStack = (PStack)stack;
	if(NULL == pStack || pStack->n == 0)
	{
		return NULL;
	}

	return pStack->datas[pStack->n--];
}

int main(int argc, char *argv[])
{

	return 0;
}
