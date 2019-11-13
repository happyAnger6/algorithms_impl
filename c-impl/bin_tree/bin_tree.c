#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"

int genData()
{
    return rand()%1000;
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <n>\r\n", argv[0]);
        return -1;
    }

    int i = 0;
    int n = atoi(argv[1]);
    BinRoot *root = malloc(sizeof(BinRoot));
    INIT_BINROOT(root, 0);

    for(i = 0; i < n; i++)
    {
       bintree_add(&root, genData()); 
    }    

    bintree_pre_traverse("root", root);
    return 0;
}
