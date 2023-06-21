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
    int widthOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
            return 0;
        int ans = 0;

        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int sz = q.size();
            int fg = 0;
            int k = 0;
            while (sz--)
            {
                auto node = q.front();
                q.pop();

                auto nd = node.first;
                int d = node.second;
                if (fg == 0)
                {
                    k = d;
                    fg = 1;
                }
                d -= k;
                if (nd->left != NULL)
                    q.push({nd->left, (long long)2 * d + 1});
                if (nd->right != NULL)
                    q.push({nd->right, (long long)2 * d + 2});

                ans = max(ans, d + 1);
            }
        }

        return ans;
    }
};