class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // nlogn
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                if (nums[j] + nums[k] + nums[i] == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    k--;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }

                else if (nums[j] + nums[k] + nums[i] > 0)
                {
                    k--;
                }
                else
                    j++;
            }
        }
        return res;
    }
};