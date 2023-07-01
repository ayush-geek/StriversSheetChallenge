class Solution
{
public:
    int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        else
        {
            int op1 = 1 + solve(i - 1, j, word1, word2, dp);     // delete
            int op2 = 1 + solve(i, j - 1, word1, word2, dp);     // insert
            int op3 = 1 + solve(i - 1, j - 1, word1, word2, dp); // replace
            dp[i][j] = min({op1, op2, op3});
        }
        return dp[i][j];
    }

    int minDistance(string word1, string word2)
    {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, word1, word2, dp);
    }
};