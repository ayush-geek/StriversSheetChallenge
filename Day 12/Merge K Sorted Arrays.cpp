#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < kArrays.size(); i++)
    {
        pq.push({-1 * kArrays[i][0], {0, i}});
    }

    vector<int> res;

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        int ind = node.second.first;
        int pos = node.second.second;
        res.push_back(-1 * node.first);
        if (ind + 1 < kArrays[pos].size())
        {
            pq.push({-1 * kArrays[pos][ind + 1], {ind + 1, pos}});
        }
    }

    return res;
}
