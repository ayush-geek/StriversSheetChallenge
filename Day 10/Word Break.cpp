class Solution
{
public:
    bool solve(int i, unordered_set<string> &st, string &s, vector<int> &dp)
    {
        if (i >= s.size())
            return true;

        if (dp[i] != -1)
        {
            if (dp[i])
                return true;
            return false;
        }

        for (int j = i; j < s.size(); j++)
        {
            int len = j - i + 1;
            string tmp = s.substr(i, len);
            if (st.count(tmp))
            {
                if (solve(j + 1, st, s, dp))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);

        return solve(0, st, s, dp);
    }
};