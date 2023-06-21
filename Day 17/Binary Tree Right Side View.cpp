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
    void solve(TreeNode *root, vector<int> &res, int k)
    {
        if (root == NULL)
            return;

        if (res.size() == k)
            res.push_back(root->val);
        solve(root->right, res, k + 1);
        solve(root->left, res, k + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        int k = 0;
        vector<int> res;

        solve(root, res, k);
        return res;
    }
};