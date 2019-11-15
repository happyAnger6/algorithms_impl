#include <stdio.h>
#include <stdlib.h>

typedef struct _heap{
    int *datas;
    int n;
}heap;

int genData()
{
    return rand()%100;
}

heap* init_heap(int n)
{
    heap* pHeap = malloc(sizeof(heap));
    pHeap->datas = malloc(sizeof(int)*n);

    int i = 0;
    for(i = 0; i < n; i++)
    {
        pHeap->datas[i] = genData(); 
    }
    pHeap->n = n;
    return pHeap;
}

void heapDown(heap *pHeap, int i)
{
    int left;
    int right;
    int max_ix = pHeap->n - 1;
    int exchg_ix = left;
    int exchg; 
    int *datas = pHeap->datas;
    int tmp;

    while(i<=max_ix)
    {
        left = 2*i+1;
        right= 2*i+2;
        if(left>max_ix && right>max_ix)
            break;

        exchg = datas[left];
        exchg_ix = left;
        if(right <= max_ix && datas[right] > exchg)
        {
            exchg_ix = right;
            exchg = datas[right];
        }

        tmp = datas[i];
        if(exchg>tmp)
        {
            datas[i] = datas[exchg_ix];
            datas[exchg_ix] = tmp;
        }
        else
        {
            break; 
        }
        i = exchg_ix;
    }
}

void build_heap(heap *pHeap)
{
    int n = pHeap->n;
    int first = (n/2 - 1); 
    while(first>=0)
    {
        heapDown(pHeap, first--);
    }
}

void print_heap(heap *pHeap)
{
    int *datas = pHeap->datas;
    int n = pHeap->n;
    int i = 0;
    printf("\r\n");
    for(i = 0; i < n; i++)
    {
        printf("[%d],", datas[i]); 
    }
    printf("\r\n");
    printf("\r\n");
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <n>\r\n", argv[0]);
        return -1; 
    }

    int n = atoi(argv[1]);
    heap *pHeap = init_heap(n);
    print_heap(pHeap);
    build_heap(pHeap);
    print_heap(pHeap);

}
