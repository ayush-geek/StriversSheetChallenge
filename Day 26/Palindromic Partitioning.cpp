//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool ispal(string &s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }
    int solve(int i, string &s, vector<int> &dp)
    {
        if (i == s.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int ans = s.size();
        for (int ind = i; ind < s.size(); ind++)
        {
            string tmp = s.substr(i, ind - i + 1);

            if (ispal(tmp))
            {
                ans = min(ans, 1 + solve(ind + 1, s, dp));
            }
        }
        return dp[i] = ans;
    }

    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int> dp(n + 1, -1);
        // when part
        return solve(0, str, dp) - 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends