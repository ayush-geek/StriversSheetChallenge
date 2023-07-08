//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find number of strongly connected components in the graph.

    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[i] = 1;

        for (auto &ele : adj[i])
        {
            if (!vis[ele])
            {
                dfs(ele, adj, vis, st);
            }
        }

        st.push(i);
    }
    void dfs2(int i, vector<int> adj[], vector<int> &vis)
    {
        vis[i] = 1;

        for (auto &ele : adj[i])
        {
            if (!vis[ele])
            {
                dfs2(ele, adj, vis);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // find order ->topt
        // reverse edges
        // dfs to cnt components

        stack<int> st;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, adj, vis, st);
        }

        vector<int> adjr[V];

        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto &ele : adj[i])
            {
                adjr[ele].push_back(i);
            }
        }

        int ct = 0;
        while (!st.empty())
        {
            int z = st.top();
            st.pop();
            if (!vis[z])
            {
                dfs2(z, adjr, vis);
                ct++;
            }
        }
        return ct;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends