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
    TreeNode *solve(int &i, int l, int r, vector<int> &inorder, vector<int> &postorder)
    {
        if (l > r)
            return NULL;
        TreeNode *rt = new TreeNode(postorder[i--]);
        int pos = -1;

        if (l == r)
            return rt;
        for (int k = l; k <= r; k++)
        {
            if (inorder[k] == rt->val)
            {
                pos = k;
                break;
            }
        }

        rt->right = solve(i, pos + 1, r, inorder, postorder);
        rt->left = solve(i, l, pos - 1, inorder, postorder);

        return rt;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = inorder.size() - 1;
        int m = postorder.size() - 1;
        return solve(m, 0, n, inorder, postorder);
    }
};