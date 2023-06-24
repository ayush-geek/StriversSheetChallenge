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
    bool isValidBST(TreeNode *root, long lft = LONG_MIN, long rgt = LONG_MAX)
    {
        if (root == NULL)
            return true;

        if (root->val >= rgt || root->val <= lft)
            return false;

        bool left = isValidBST(root->left, lft, root->val);
        bool regt = isValidBST(root->right, root->val, rgt);
        return left && regt;
    }
};