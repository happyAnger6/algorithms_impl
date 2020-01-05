#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

typedef struct{
    char data[MAX_ELEMENTS];
    int top;
}stack, *pstack;

typedef int bool;

void stack_init(pstack s)
{
    s->top = -1;
}

int stack_push(pstack s, char c)
{
    if(s->top+1>=MAX_ELEMENTS)
    {
        return -1; 
    }

    s->data[++s->top] = c;
    return 0;
}

char stack_pop(pstack s)
{
    if(s->top>=0)
    {
        return s->data[s->top--]; 
    }
    return 0;
}

bool stack_empty(pstack s)
{
    return s->top == -1;
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <str>\r\n", argv[0]);
        return -1; 
    }

    char *s = argv[1];
    int i;
    char c;
    pstack st= malloc(sizeof(stack));
    stack_init(st);
    int len = strlen(s);
    int wrong;
    for(i = 0; i < len; i++)
    {
        if(s[i]==')')
        {
            c = stack_pop(st);
            if(c!='(')
            {
                wrong = 1;
                break; 
            } 
        } 
        else if(s[i]==']')
        {
            c = stack_pop(st);
            if(c!='[')
            {
                wrong = 1;
                break; 
            } 
        
        }
        else if(s[i]=='}')
        {
            c = stack_pop(st);
            if(c!='{')
            {
                wrong = 1;
                break; 
            } 
        }
        else if(s[i]=='(' || s[i] == '{' || s[i] == '[')
        {
            stack_push(st, s[i]);
        }
        else
        {
            wrong = 1;
            break; 
        }
    }

    if(!wrong && stack_empty(st))
    {
        printf("match\r\n");
        return 0; 
    }

    printf("no match\r\n");
    return 1;
}
