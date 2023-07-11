//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int arr[], int n)
    {
        vector<int> res(n, 0);
        vector<int> sl; // smaller left
        vector<int> sr; // smaller right
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                sl.push_back(-1);
            else
                sl.push_back(st.top());
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                sr.push_back(n);
            else
                sr.push_back(st.top());
            st.push(i);
        }

        reverse(sr.begin(), sr.end());

        for (int i = 0; i < n; i++)
        {
            // cout<<i<<" "<<sl[i]<<" "<<sr[i]<<endl;
            int d = sr[i] - sl[i] - 1 - 1;

            res[d] = max(res[d], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            res[i] = max(res[i], res[i + 1]);
        }

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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        vector<int> res = ob.maxOfMin(a, n);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends