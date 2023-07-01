//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.

    int solve(int i, int j, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int p = 0, np = 0;

        if (j >= wt[i])
            p = val[i] + solve(i + 1, j - wt[i], wt, val, n, dp);

        np = solve(i + 1, j, wt, val, n, dp);

        return dp[i][j] = max(p, np);
    }

    int knapSack(int W, int wt[], int val[], int n)
    {

        // Try  out all possibilities
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(0, W, wt, val, n, dp);
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
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends