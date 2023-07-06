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
    TreeNode *solve(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;

        int mid = (l) + (r - l) / 2;

        TreeNode *rt = new TreeNode(nums[mid]);
        rt->left = solve(nums, l, mid - 1);
        rt->right = solve(nums, mid + 1, r);

        return rt;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        return solve(nums, l, r);
    }
};