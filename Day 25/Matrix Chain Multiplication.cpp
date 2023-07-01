//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int i, int j, int arr[], vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int ind = i; ind < j; ind++)
        {
            int cur = arr[i - 1] * arr[ind] * arr[j] + solve(i, ind, arr, dp) + solve(ind + 1, j, arr, dp);
            ans = min(ans, cur);
        }

        return dp[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // Here at each partition answer varies
        // Parition dp
        // should be something to ponder

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return solve(1, N - 1, arr, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends