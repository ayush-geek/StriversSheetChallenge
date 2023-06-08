//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        unordered_map<int, int> mp;
        int ans = 0;

        int sm = 0;
        int k = 0;
        mp[0] = -1;
        for (auto &ele : A)
        {
            sm += ele;

            if (ele == 0)
            {
                ans = max(ans, 1);
            }

            if (mp.count(sm) == 1)
            {
                ans = max(ans, k - mp[sm]);
            }

            else
                mp[sm] = k;
            k++;
        }

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
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends