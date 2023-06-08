class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int n = s.size();
        int i = 0;

        int ans = 0;
        unordered_map<int, int> mp;

        for (int j = 0; j < n; j++)
        {
            while (mp[s[j]] > 0)
            {
                mp[s[i]]--;
                i++;
            }
            mp[s[j]] = 1;

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};