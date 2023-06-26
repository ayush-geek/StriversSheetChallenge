class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &pre)
    {
        vector<int> in(n, 0);
        vector<int> adj[n];
        for (int i = 0; i < pre.size(); i++)
        {
            int a = pre[i][0], b = pre[i][1];
            adj[b].push_back(a);
            in[a]++;
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
                q.push(i);
            // cout<<i<<" "<<in[i]<<endl;
        }

        while (!q.empty())
        {
            auto nd = q.front();
            q.pop();
            res.push_back(nd);
            for (auto &ele : adj[nd])
            {
                in[ele]--;
                if (in[ele] == 0)
                    q.push(ele);
            }
        }
        return res.size() == n;
    }
};