class Solution
{
public:
    void solve(int i, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res)
    {
        int n = nums.size();

        res.push_back(tmp);

        for (int j = i; j < n; j++)
        {
            if (j != i && nums[j] == nums[j - 1])
                continue;

            tmp.push_back(nums[j]);
            solve(j + 1, nums, tmp, res);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        solve(0, nums, tmp, res);
        return res;
    }
};
