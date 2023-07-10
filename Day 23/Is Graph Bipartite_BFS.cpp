class Solution
{
public:
    bool dfs(int i, int pcol, vector<vector<int>> &graph, vector<int> &col)
    {
        col[i] = pcol;

        for (auto &ele : graph[i])
        {
            if (col[ele] == 0)
            {
                if (dfs(ele, -1 * pcol, graph, col))
                    return true;
            }
            else if (col[ele] == pcol)
                return true;
        }
        return false;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> col(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (col[i] == 0)
            {
                // if(dfs(i,-1,graph,col))
                //     return false;

                queue<int> q;
                q.push(i);
                col[i] = -1;

                while (!q.empty())
                {
                    auto nd = q.front();
                    q.pop();

                    for (auto &ele : graph[nd])
                    {
                        if (col[ele] == 0)
                        {
                            col[ele] = -1 * col[nd];
                            q.push(ele);
                        }
                        else if (col[ele] == col[nd])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};