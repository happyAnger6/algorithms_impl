#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
}*link;


link new_node(int v)
{
	link new = malloc(sizeof(*link));
	new->data = v;
	new->next = NULL;
	return new;
}

link add_two_numbers(link h1, link h2)
{
	int carray = 0;
	int v = 0;
	int sum = 0;
	link head = new_node(-1);
	link cur = head;
	while(h1!=NULL || h2!=NULL)
	{
		n1 = h1? h1->data : 0;
		n2 = h2? h2->data : 0;
		sum = n1 + n2 + carry;
		carry = sum/10;
		v = sum%10;
		
		cur->next = new_node(v);
		cur = cur->next;	

		if(h1) h1=h1->next;
		if(h2) h2=h2->next;
	}

	if(carry)	cur->next = new_node(carry);
	return head->next;
}
