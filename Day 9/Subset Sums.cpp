//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(int i, vector<int> &nums, int tmp, vector<int> &res)
    {
        int n = nums.size();
        if (i == nums.size())
        {
            res.push_back(tmp);
            return;
        }

        solve(i + 1, nums, tmp + nums[i], res);

        solve(i + 1, nums, tmp, res);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here

        vector<int> res;
        int tmp = 0;
        solve(0, arr, tmp, res);
        return res;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends