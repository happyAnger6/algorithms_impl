#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data[MAX_ELEMENTS];
    int top;
}STACK_S, *PSTACK;

typedef int bool;

void stack_init(PSTACK s)
{
    s->top = -1;
}

int stack_push(PSTACK s, int c)
{
    if(s->top+1>=MAX_ELEMENTS)
    {
        return -1; 
    }

    s->data[++s->top] = c;
    return 0;
}

int stack_pop(PSTACK s)
{
    if(s->top>=0)
    {
        return s->data[s->top--]; 
    }
    return 0;
}

bool stack_empty(PSTACK s)
{
    return s->top == -1;
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <expression>\r\n");
        return -1; 
    }

    char *s = argv[1];
    char c;
    int res, d;
    int sign = 1;

    int i = 0;
    int len = strlen(s);
    PSTACK stack = malloc(sizeof(STACK_S));
    stack_init(stack);

    for(i = 0; i < len; i++)
    {
        c = s[i];
        if('0' <= c && c <= '9')
        {
            d = d*10 + c - '0';
        } 
        else
        {
            if(sign=='-')
              stack_push(-d);
            if(sign=='+') 
              stack_push(d);
            if(sign == '*' || sign == '/')
            {
                int tmp = sign == '*'? stack_pop(stack) * d : stack_pop(stack)/d;
                stack.push(tmp);
            }
            sign = c;
            d = 0;
        }        
    }

    while(!stack_empty(stack))
        res += stack_pop(stack);

    printf("[%d]\r\n", res);
}
