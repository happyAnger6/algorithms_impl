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
    while(NULL != root)
        traverse(root);

    pre_reverse(root->left); 
    pre_reverse(root->right); 
}

int main(int argc, char *argv[])
{
    return 0;
}


