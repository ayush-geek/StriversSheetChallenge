void changeTree(BinaryTreeNode<int> *root)
{
    // Write your code here.

    if (root == NULL)
        return;
    int sm = 0;
    if (root->left)
    {
        sm += root->left->data;
    }

    if (root->right)
    {
        sm += root->right->data;
    }

    if (sm >= root->data)
        root->data = sm;

    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;

    if (root->left or root->right)
        root->data = tot;

    return;
}