//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int solve(int i, int coins[], vector<vector<int>> &dp, int V)
    {
        if (i < 0)
        {
            if (V == 0)
                return 0;
            return 1e9;
        }

        if (dp[i][V] != -1)
            return dp[i][V];

        int ans = 1e9;
        if (coins[i] <= V)
        {
            ans = 1 + solve(i, coins, dp, V - coins[i]);
        }

        int nt = solve(i - 1, coins, dp, V);

        return dp[i][V] = min(ans, nt);
    }

    int minCoins(int coins[], int M, int V)
    {
        // Your code goes here

        vector<vector<int>> dp(M, vector<int>(V + 1, -1));
        sort(coins, coins + M);
        int ans = solve(M - 1, coins, dp, V);

        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends