//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {

        int l = 0;
        int r = min(n, k);
        int z = r;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            int cut1 = mid;
            int cut2 = min(k - mid, m);

            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];

            if (l1 <= r2 && l2 <= r1 && cut1 + cut2 == k)
            {
                return max(l1, l2);
            }

            else if (l1 > r2)
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return -1;
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
        int n, m, k;
        cin >> n >> m >> k;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    }
    return 0;
}
// } Driver Code Ends