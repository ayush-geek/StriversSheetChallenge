/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return build(i, preorder, INT_MAX);
    }

    TreeNode *build(int &i, vector<int> &preorder, int ub)
    {
        if (i == preorder.size() || preorder[i] > ub)
            return NULL;
        TreeNode *tmp = new TreeNode(preorder[i++]);
        tmp->left = build(i, preorder, tmp->val);
        tmp->right = build(i, preorder, ub);
        return tmp;
    }
};