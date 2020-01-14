#include "pqueue.h"


typedef struct{
	int data;
}pq_element;

const struct pq_operations pq_ops = {
	.init_elements = pq_init_element,
	.cmp_elements = pq_cmp_elements,
	.element_size = pq_element_size,	
};

int pq_element_size()
{
	return sizeof(int);
}

int pq_cmp_elements(void *e1, void *e2)
{
	int p1 = (pq_element *)e1;
	int p2 = (pq_element *)e2;

	return p1->data - p2->data;
}

int pq_init_element(void *ele)
{
	pq_element *p = (pq_element *)ele;
	p->data = -1;	

	return 0;
}

pqueue* pq_create(
