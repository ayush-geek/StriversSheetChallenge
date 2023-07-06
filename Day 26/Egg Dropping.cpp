//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.

    int solve(int n, int k, vector<vector<int>> &dp)
    {
        if (n <= 1)
            return n;

        if (k == 1)
            return n;

        if (dp[n][k] != -1)
            return dp[n][k];

        int mn = INT_MAX;
        for (int j = 1; j <= n; j++)
        {

            int a = solve(j - 1, k - 1, dp);
            int b = solve(n - j, k, dp);

            mn = min(mn, 1 + max(a, b));
        }

        return dp[n][k] = mn;
    }

    int eggDrop(int n, int k)
    {
        // MCM

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends