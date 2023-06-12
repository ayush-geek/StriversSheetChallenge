//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {

        // max intersectiom
        // line sweep algo

        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back({arr[i], dep[i]});
        }
        // 9 to 11
        // 11 to 1

        map<int, int> mp;

        for (auto &ele : vp)
        {
            int a = ele.first;
            int b = ele.second;

            mp[a]++;
            mp[b + 1]--;
        }

        int mx = 0;
        int sm = 0;
        for (auto &ele : mp)
        {
            // cout<<ele.first<<" "<<ele.second<<endl;
            sm += ele.second;
            mx = max(mx, sm);
        }

        return mx;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
}
// } Driver Code Ends