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

void mid_reverse(tnode *root)
{
    if(NULL == root)
		return;
    
    pre_reverse(root->left); 
	traverse(root);
    pre_reverse(root->right); 
}

void mid_reverse_no_recursive(tnode *root)
{
    Stack stack;
    cur = root;
    while(!stack_isEmpty() || cur!=NULL)
    {
        if(cur!=NULL)
        {
            stack_push(cur);
            cur = cur-left;
        } 
        else
        {
            cur = stack_pop();
            traverse(cur);
            cur = cur->right;
        }

    }
}

void mid_reverse_no_recursive1(tnode *root)
{
    Stack stack;
    cur = root;
    while(cur!=NULL)
    {
        while(cur->left)
        {
            stack_push(cur);
            cur = cur-left;
        } 
        traverse(cur);
        if(cur->right)
        {
            cur = cur->right; 
        }
        else
        {
            cur = stack_pop(); 
        }


    }
}
