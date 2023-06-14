class Solution
{
public:
    bool valid(int i, int j, vector<string> &tmp)
    {

        int cr = i;
        int cc = j;

        //-45 degree
        while (cr >= 0 && cc >= 0)
        {
            if (tmp[cr][cc] == 'Q')
                return false;
            cr--;
            cc--;
        }

        cr = i;
        cc = j;

        // 45 degree
        while (cr >= 0 && cc < tmp.size())
        {
            if (tmp[cr][cc] == 'Q')
                return false;
            cr--;
            cc++;
        }

        cr = i;
        cc = j;

        // 90 degree
        while (cr >= 0)
        {
            if (tmp[cr][cc] == 'Q')
                return false;
            cr--;
        }
        // rows already taken care of
        return true;
    }

    void solve(int i, int n, vector<string> &tmp, vector<vector<string>> &res)
    {
        if (i == n)
        {
            res.push_back(tmp);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (valid(i, j, tmp))
            {
                tmp[i][j] = 'Q';
                solve(i + 1, n, tmp, res);
                tmp[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        solve(0, n, tmp, res);
        return res;
    }
};