int Solution::solve(string s)
{

    string rev = s;
    reverse(rev.begin(), rev.end());
    string tmp = s + "#" + rev;
    int n = tmp.size();
    // compute lps
    vector<int> lps(n, 0);

    int j = 0;
    int i = 1;

    while (i < n)
    {
        if (tmp[i] == tmp[j])
        {
            lps[i] = j + 1;
            j++;
            i++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }

    string tt = rev.substr(0, s.size() - lps[n - 1]) + s;
    return tt.size() - s.size();
}
