class Solution
{
public:
    unordered_map<int, bool> mp;
    bool solve(int i, string s, unordered_set<string> &st)
    {
        if (i == s.size())
        {
            return true;
        }

        if (mp.count(i) == 1)
            return mp[i];
        bool ans = false;
        for (int j = i; j < s.size(); j++)
        {
            string tmp = s.substr(i, j - i + 1);

            if (st.count(tmp) == 1)
            {
                ans = solve(j + 1, s, st);

                if (ans == true)
                    return true;
            }
        }
        return mp[i] = ans;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        return solve(0, s, st);
    }
};