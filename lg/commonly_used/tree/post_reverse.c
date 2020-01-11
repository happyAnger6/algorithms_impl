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

void post_reverse(tnode *root)
{
    if(NULL == root)
		return;
    
    pre_reverse(root->left); 
    pre_reverse(root->right); 
	traverse(root);
}

void post_reverse_no_recursive(tnode *root)
{
    tnode *last = NULL, *cur = root; 
    stack_push(cur);
    while(!stack_empty())
    {
        cur = stack_peek();
        if(cur->left != NULL && h != cur->left && h != cur->right)
        {
            stack_push(cur->left); 
        }
        else if(cur->right != NULL && h != cur->right)
        {
            stack_push(cur->right); 
        }
        else
        {
            traverse(cur);
            h = cur; 
        }
    }
}










