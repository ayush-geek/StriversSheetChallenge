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
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &idx, int l, int r)
    {
        if (l > r)
            return NULL;
        int pivot = l;

        while (inorder[pivot] != preorder[idx])
        {
            pivot++;
        }

        idx++;
        TreeNode *newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, idx, l, pivot - 1);
        newNode->right = build(preorder, inorder, idx, pivot + 1, r);

        return newNode;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int rtidx = 0;

        return build(preorder, inorder, rtidx, 0, inorder.size() - 1);
    }
};