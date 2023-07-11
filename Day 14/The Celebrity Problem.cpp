//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (M[i][j])
                i++;
            else
                j--;
        }

        for (int k = 0; k < n; k++)
        {
            if (k == i)
                continue;
            if (M[k][i] == 0 || M[i][k] == 1)
                return -1;
        }

        //     vector<int> cel(n,0);

        //     for(int i=0;i<n;i++)
        //     {
        //         for(int j=0;j<n;j++)
        //         {
        //             if(M[i][j]==1)
        //                 cel[i]=1;

        //         }
        //     }
        //     int cnt=0;
        //     int pos=0;
        //     for(int i=0;i<n;i++)
        //     {
        //         if(cel[i]==0)
        //             {
        //                 pos=i;
        //                 cnt++;
        //             }
        //     }
        //   // cout<<cnt<<endl;
        //     if(cnt==0 ||cnt>1)
        //         return -1;
        //     cnt=0;
        //     for(int i=0;i<n;i++)
        //     {
        //         if(i==pos)
        //             continue;
        //         if(M[i][pos]==1)
        //             {
        //                 cnt++;
        //             }
        //     }

        //     if(cnt==n-1)
        //         return pos;
        //     else
        //         return -1;

        return i;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends