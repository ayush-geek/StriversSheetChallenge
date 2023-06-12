//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, int>> dp;
        for (int i = 0; i < n; i++)
        {
            double ans = (1.0 * arr[i].value) / arr[i].weight;
            dp.push_back({ans, i});
        }

        sort(dp.rbegin(), dp.rend());

        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            int ind = dp[i].second;
            if (W >= arr[ind].weight)
            {
                ans += arr[ind].value;
                W -= arr[ind].weight;
            }
            else if (W > 0)
            {
                ans += dp[i].first * W;
                W = 0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends