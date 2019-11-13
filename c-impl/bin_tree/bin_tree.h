#ifndef _BIN_TREE_H
#define _BIN_TREE_H

typedef struct _binNode{
    int iData;
    struct _binNode *pLeft;
    struct _binNode *pRight;
}BinNode;


typedef BinNode BinRoot;

#define INIT_BINROOT(root, data)    { root->iData = data;\
                            root->pLeft = NULL; \
                            root->pRight = NULL; }
        
#define BINROOT(name, data) BinRoot name = { .iData = data, \
        .pLeft = NULL,\
        .pRight = NULL,\
 }

static inline int bintree_add(BinRoot **ppRoot, int data)
{
    BinRoot **ppPos = ppRoot;
    BinRoot *pTmp = *ppPos;

    BinNode *pNode = malloc(sizeof(BinNode));
    if(NULL == pNode)
        return -1;
    pNode->iData = data;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;

    
    while(pTmp != NULL)
    {
        if(data <= pTmp->iData)
            ppPos = &(pTmp->pLeft);
        else
            ppPos = &(pTmp->pRight);
        pTmp = *ppPos;
    }
    *ppPos = pNode;
    return 0;

}

static inline int bintree_rm(BinRoot **ppRoot, int data)
{
    BinNode *pRmNode = *ppRoot;
    if(NULL == pRoot)
    {
        return -1;
    }

    BinNode **ppPos = ppRoot;
    while(NULL != pRoot)
    {
        if(pRmNode->data == data)
            break;

        if(pRmNode->data > data)
        {
            pRmNode = pRoot->pLeft;
            **ppPos = &(pRoot->pLeft);
        }
        else
        {
            pRmNode = pRoot->pRight;
            **ppPos = &(pRoot->pRight);
        }
    }

    if(pRoot == NULL)
        return -1;


    if(pRmNode->pLeft && pRmNode->pRight)
    {
        BinNode **ppPos1 = &(pRmNode->pRight);
        BinNode *pRmNode1 = pRmNode->pRight;
        while(pRmNode1->pLeft)
        {
            ppPos1 = &(pRmNode1->pLeft);
            pRmNode1 = pRmNode1->pLeft;
        }
        ppPos = ppPos1;
        pRmNode->iData = pRmNode1->iData;
        pRmNode = pRmNode1;
    }    

    BinNode *pChild = NULL;
    if(pRmNode->pLeft)
        pChild=pRmNode->pLeft;
    else if(pRmNode->pRight)
        pChild=pRmNode->pRight;

    **ppPos = pChild;
    return 0;
}

static inline int bintree_pre_traverse(char *pcMsg, BinRoot *pRoot)
{
    if(NULL != pRoot)
    {
        printf("%s:[%d] ", pcMsg, pRoot->iData);
        bintree_pre_traverse("left", pRoot->pLeft);
        bintree_pre_traverse("right", pRoot->pRight);
    }
}

#endif
