vector<int> Solution::dNums(vector<int> &A, int B)
{
    vector<int> res;
    unordered_map<int, int> mp;
    int cd = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (i >= B)
        {
            mp[A[i - B]] -= 1;
            if (mp[A[i - B]] == 0)
                cd--;
        }
        if (mp[A[i]] == 0)
            cd++;
        mp[A[i]]++;
        if (i >= B - 1)
        {
            res.push_back(cd);
        }
    }
    return res;
}
