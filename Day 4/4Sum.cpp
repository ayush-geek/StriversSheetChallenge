class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            // int j=i+1;
            for (int j = i + 1; j < n; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l)
                {
                    long long val = 1ll * nums[i] + 1ll * nums[j] + 1ll * nums[k] + 1ll * nums[l];

                    if (val == 1ll * target)
                    {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (val < 1ll * target)
                    {
                        k++;
                    }
                    else
                        l--;
                }
            }
        }
        return res;
    }
};