class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        vector<int> lis;

        // nlogn

        for (int i = 0; i < nums.size(); i++)
        {
            if (lis.empty() || lis.back() < nums[i])
                lis.push_back(nums[i]);
            else
            {
                int lb = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[lb] = nums[i];
            }
        }
        return lis.size();
    }
};