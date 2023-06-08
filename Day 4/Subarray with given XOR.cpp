int Solution::solve(vector<int> &A, int B)
{

    int ans = 0;
    unordered_map<int, int> mp;
    int val = 0;
    mp[0] = 1;
    for (int i = 0; i < A.size(); i++)
    {
        val = val ^ A[i];

        if (mp.count(val ^ B))
        {
            ans += mp[val ^ B];
        }

        mp[val]++;
    }

    return ans;
}
