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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        int fg = 0;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> tmp;
            while (sz--)
            {
                auto nd = q.front();
                tmp.push_back(nd->val);
                q.pop();

                if (nd->left != NULL)
                    q.push(nd->left);
                if (nd->right != NULL)
                    q.push(nd->right);
            }
            if (fg == 1)
                reverse(tmp.begin(), tmp.end());
            fg = 1 - fg;
            res.push_back(tmp);
        }
        return res;
    }
};