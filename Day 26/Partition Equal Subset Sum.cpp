class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {

        int sm = accumulate(nums.begin(), nums.end(), 0);

        if (sm % 2 != 0)
            return false;
        int tgt = sm / 2;

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(tgt + 1, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= tgt; j++)
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]];

                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }

        return dp[n][tgt];
    }
};