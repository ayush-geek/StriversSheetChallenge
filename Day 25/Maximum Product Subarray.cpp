class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int pos = 1, neg = 1;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                swap(pos, neg);
            }

            pos = max(nums[i], pos * nums[i]);
            neg = max(nums[i], neg * nums[i]);
            ans = max(ans, pos);
        }
        return ans;
    }
};