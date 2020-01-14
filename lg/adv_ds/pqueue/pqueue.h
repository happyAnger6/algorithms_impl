#ifndef _PQUEUE_H
#define _PQUEUE_H

struct pq_operations{
	int init_elements(void *ele);
	int fini_elements(void *ele);
	int cmp_elements(void *e1, void *e2);
	int element_size();	
};

typedef struct{
	int cap;
	int size;
	
}pqueue;

pqueue* pq_create(struct pq_operations *);
int pq_add(pqueue *pq, int pri, void *ele);
void* pq_pop(pqueue *pq, int pri);
int pq_destory(pqueue *pq);

#endif
