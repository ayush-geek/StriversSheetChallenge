class Solution
{
public:
    bool pal(string ss)
    {
        int i = 0;
        int j = ss.size() - 1;

        while (i < j)
        {
            if (ss[i] != ss[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int i, string s, vector<vector<string>> &res, vector<string> &tmp)
    {
        if (i == s.size())
        {
            res.push_back(tmp);
            return;
        }

        int n = s.size();
        for (int j = i; j < n; j++)
        {
            string cur = s.substr(i, j - i + 1);

            if (pal(cur))
            {
                tmp.push_back(cur);
                solve(j + 1, s, res, tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {

        vector<vector<string>> res;
        int n = s.size();

        // try all case
        vector<string> tmp;
        solve(0, s, res, tmp);

        return res;
    }
};