class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        int mxp = 0;
        int mnp = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < mnp)
                mnp = nums[i];

            mxp = max(mxp, nums[i] - mnp);
        }
        return mxp;
    }
};