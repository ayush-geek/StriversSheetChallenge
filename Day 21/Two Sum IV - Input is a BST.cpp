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
class BSTIterator
{
private:
    stack<TreeNode *> st;
    int reverse;

    void pushlft(TreeNode *rt, bool reverse)
    {
        while (rt != NULL)
        {
            st.push(rt);

            if (reverse)
                rt = rt->right;
            else
                rt = rt->left;
        }
    }

public:
    BSTIterator(TreeNode *root, bool reverse)
    {
        this->reverse = reverse;
        pushlft(root, reverse);
    }

    int next()
    {
        TreeNode *tmp = st.top();
        st.pop();

        if (reverse)
            pushlft(tmp->left, reverse);
        else
            pushlft(tmp->right, reverse);
        return tmp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

class Solution
{
public:
    void solve(TreeNode *rt, vector<int> &in)
    {

        if (rt == NULL)
            return;
        solve(rt->left, in);
        in.push_back(rt->val);
        solve(rt->right, in);
    }

    bool findTarget(TreeNode *root, int k)
    {

        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};