class Solution
{
public:
    void solve(int i, int target, vector<int> &candidates, vector<int> &tmp, vector<vector<int>> &res)
    {
        int n = candidates.size();

        if (target == 0)
        {
            res.push_back(tmp);
            return;
        }

        for (int j = i; j < n; j++)
        {
            if (j != i && candidates[j] == candidates[j - 1])
                continue;

            if (candidates[j] <= target)
            {
                tmp.push_back(candidates[j]);
                solve(j + 1, target - candidates[j], candidates, tmp, res);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        solve(0, target, candidates, tmp, res);

        return res;
    }
};