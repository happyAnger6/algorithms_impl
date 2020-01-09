#include <stdio.h>
#include <stdlib.h>

typedef struct dnode_{
    int data;
    struct dnode_ *next;
    struct dnode_  *prev;
}dnode;

typedef struct dqueue_{
    int len;
    int cap;
    dnode dq;
}dqueue, *pDqueue;

void dqueue_init(pDqueue dq);
int dqueue_add_head(pDqueue dq, int data);
int dqueue_add_tail(pDqueue dq, int data);
int dqueue_del_head(pDqueue dq);
int dqueue_del_tail(pDqueue dq);
int dqueue_get_head(pDqueue dq);

int dqueue_push(pDqueue dq, int a);
{
    if(dqueue_len(dq)==dq->cap)
    {
        dqueue_del_head(dq); 
    }

    for_each_dnode_from_tail(dq, d)
    {
        if(a>d->data)
        {
           dqueue_del_node(d);
        }
        else
        {
            break; 
        } 
    }
}

int main(int argc, char *argv[])
{
    int n = 0;
    int k = 0;
    int i;
    if(argc<3)
    {
        printf("usage:%s <k> <nums...>\r\n");
        return -1; 
    }

    k = atoi(argv[1]);
    n = argc-2;
    int *pNums = malloc(sizeof(int) * n);
    int *pResults = malloc(sizeof(int) * (n-2));
    for(i = 2; i < argc; i++)
        pNums[i-2] = atoi(argv[i]);

    for(i = 0; i < n; i++)
    {
        if(i==0)
        {
            init_dqueue(pNums, k); 
            i+=k;
        }
        pResults[i-k]=dqueue_head();
    }
}
