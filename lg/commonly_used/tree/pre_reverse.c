#include <stdio.h>
#include <stdlib.h>

typedef struct tnode_{
    void *data;
    struct tnode_ *left;
    struct tnode_ *right;
}tnode;

tnode troot;

void traverse(tnode *node)
{
    printf(" [%d] ", node->data);
}

void pre_reverse(tnode *root)
{
    if(NULL == root)
		return;
    
	traverse(root);
    pre_reverse(root->left); 
    pre_reverse(root->right); 
}


void pre_reverse_no_recursive1(tnode *root)
{
	stack_push(root);
	while(NULL != (cur = stack_pop()))
	{
        traverse(cur);
		if(cur->right)
			stack_push(cur->right);
		if(cur->left)
			stack_push(cur->left);
	}
}

void pre_reverse_no_recursive(tnode *root)
{
	tnode *cur = root;
	while(cur != NULL)
	{
		if(cur->left && cur->right)
		{
			stack_push(cur);
			cur = cur->left;
		}
		else if(cur->left)
		{
			cur = cur->left;
		}
		else if(cur->right)
		{
			cur = cur->right;
		}
		else
		{
			top = stack_pop();
			if(top == NULL)
				break;
			cur = top->right;
		}
	}	

	return;
}

int main(int argc, char *argv[])
{
    return 0;
}


