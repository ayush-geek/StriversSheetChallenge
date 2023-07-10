class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 1;
                    q.push({0, {i, j}});
                }
                else if (grid[i][j] == 1)
                    ct++;
            }
        }
        int ans = 0;
        while (!q.empty())
        {
            auto nd = q.front();
            q.pop();
            int tm = nd.first;
            int r = nd.second.first;
            int c = nd.second.second;
            ans = max(ans, tm);

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
                {
                    q.push({tm + 1, {nr, nc}});
                    vis[nr][nc] = 1;
                    ct--;
                }
            }
        }
        if (ct != 0)
            return -1;
        return ans;
    }
};