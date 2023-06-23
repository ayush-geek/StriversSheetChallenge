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
    int solve(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int lmx = max(0, solve(root->left, ans));

        int rmx = max(solve(root->right, ans), 0);

        ans = max({ans, lmx + rmx + root->val});

        return max(lmx, rmx) + root->val;
    }

    int maxPathSum(TreeNode *root)
    {

        int ans = INT_MIN;
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return root->val;
        solve(root, ans);

        return ans;
    }
};