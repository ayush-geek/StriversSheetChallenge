//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU
{

public:
    vector<int> parent, size;

    DSU(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findUpar(int nd)
    {
        if (parent[nd] == nd)
            return nd;

        return parent[nd] = findUpar(parent[nd]);
    }

    bool unionBySize(int a, int b)
    {
        int pa = findUpar(a);
        int pb = findUpar(b);

        if (pa == pb)
            return false;

        if (size[pa] < size[pb])
        {
            size[pb] += size[pa];
            parent[pa] = pb;
        }
        else
        {
            size[pa] += size[pb];
            parent[pb] = pa;
        }

        return true;
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> vpp;
        vector<int> vis(V, 0);
        DSU ds(V);
        for (int i = 0; i < V; i++)
        {
            for (auto &ele : adj[i])
            {
                vpp.push_back({ele[1], {ele[0], i}});
            }
        }

        sort(vpp.begin(), vpp.end());
        int ans = 0;

        for (auto &ele : vpp)
        {
            int a = ele.first;
            int b = ele.second.first;
            int c = ele.second.second;

            if (ds.unionBySize(b, c))
                ans += a;
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;

        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends