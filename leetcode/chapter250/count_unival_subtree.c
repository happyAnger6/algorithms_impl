int count_unival_subtree(tnode *root)
{
    int cnt = 0;
    if(root == NULL) return res;
    if(unival_tree(root, root->val)) return res++;
    res+=count_unival_subtree(root->left);
    res+=count_unival_subtree(root->right);
    return res;
}

int unival_tree(tnode *node, int val)
{
    if(node == NULL) return 1;
    return node->val == val && unival_tree(node->left, val) && unival_tree(node->right, val);
}

int unival_tree_no_recursive(tnode *node, int val)
{
    stack_push(node);
    while((cur=stack_pop())!=NULL)
    {
        if(cur->val != val)
            return 0;
        stack_push(cur->right);
        stack_push(cur->left);
    }
    return 1;
}
