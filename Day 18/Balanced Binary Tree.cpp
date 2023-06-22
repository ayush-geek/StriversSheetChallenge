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
    int solve(TreeNode *root, bool &fg)
    {
        if (root == NULL)
            return 0;
        int lh = solve(root->left, fg);
        int rh = solve(root->right, fg);

        if (abs(lh - rh) > 1)
            fg = true;

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode *root)
    {

        bool fg = false;
        int ht = solve(root, fg);
        return fg == false;
    }
};