class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();

        // kadane's  Algorithm
        int sm = nums[0];
        int mx = nums[0];
        for (int i = 1; i < n; i++)
        {
            sm = max(sm + nums[i], nums[i]);
            mx = max(mx, sm);
        }
        return mx;
    }
};