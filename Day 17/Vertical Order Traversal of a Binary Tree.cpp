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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        map<int, multiset<pair<int, int>>> mp;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        int r = 0;
        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                auto node = q.front();
                q.pop();

                auto nd = node.first;
                int d = node.second;
                mp[d].insert({r, nd->val});
                if (nd->left != NULL)
                {
                    q.push({nd->left, d - 1});
                }

                if (nd->right != NULL)
                {
                    q.push({nd->right, d + 1});
                }
            }
            r++;
        }

        for (auto &ele : mp)
        {
            vector<int> tmp;
            for (auto &it : ele.second)
            {
                tmp.push_back(it.second);
            }
            res.push_back(tmp);
        }

        return res;
    }
};