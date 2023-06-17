vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    priority_queue<pair<int, pair<int, int>>> pq;
    int i = 0, j = 0;
    pq.push({(A[i] + B[j]), {0, 0}});
    vector<int> res;
    set<vector<int>> st;
    priority_queue<int> tmp;
    while (tmp.size() < C)
    {
        auto nd = pq.top();
        pq.pop();

        int val = nd.first;
        int r = nd.second.first;
        int c = nd.second.second;

        tmp.push(-1 * val);

        if (st.count({r + 1, c}) == 0 && r + 1 < A.size())
        {
            pq.push({A[r + 1] + A[c], {r + 1, c}});
            st.insert({r + 1, c});
        }

        if (st.count({r, c + 1}) == 0 && c + 1 < B.size())
        {
            pq.push({A[r] + A[c + 1], {r, c + 1}});
            st.insert({r, c + 1});
        }
    }

    while (!tmp.empty())
    {
        res.push_back(abs(tmp.top()));
        tmp.pop();
    }

    sort(res.rbegin(), res.rend());
    return res;
}
