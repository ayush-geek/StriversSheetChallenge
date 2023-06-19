class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        string res = "";
        int mx = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                int len = j - i + 1;
                if (i == j)
                    dp[i][j] = 1;
                else if (s[i] == s[j])
                {
                    if (len == 2)
                        dp[i][j] = 2;
                    else if (dp[i + 1][j - 1] > 0)
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                }

                if (dp[i][j] > mx)
                {
                    mx = dp[i][j];
                    res = s.substr(i, len);
                }
            }
        }
        return res;
    }
};