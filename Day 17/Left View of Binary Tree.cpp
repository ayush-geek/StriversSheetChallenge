void solve(Node *root, int ch, vector<int> &res)
{
    if (root == NULL)
        return;

    if (ch == res.size())
        res.push_back(root->data);

    solve(root->left, ch + 1, res);
    solve(root->right, ch + 1, res);
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> res;
    int ch = 0; // Current height
    solve(root, ch, res);
    return res;
}