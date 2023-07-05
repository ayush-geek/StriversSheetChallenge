class Solution
{
public:
    long long solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        // cout<<i<<" "<<j<<endl;
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        long long ans = 1e9;
        int fg = 0;
        for (int pos = i; pos <= j; pos++)
        {
            fg = 1;

            long long tmp = (cuts[j + 1] - cuts[i - 1]) + solve(i, pos - 1, cuts, dp) + solve(pos + 1, j, cuts, dp);
            // cout<<tmp<<endl;
            ans = min(ans, tmp);
        }

        // if(fg==0)
        //     return dp[i][j]=(cuts[j]-cuts[i]);

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int> &cuts)
    {

        // dp
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));

        return solve(1, m - 2, cuts, dp);
    }
};