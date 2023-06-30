//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {

        vector<string> res;

        for (int i = 1; i < (1 << (s.size())); i++)
        {
            string tmp;
            for (int j = 0; j < s.size(); j++)
            {
                if (i & (1 << j))
                    tmp.push_back(s[j]);
            }
            res.push_back(tmp);
        }

        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends