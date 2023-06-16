class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        for (auto &ele : nums)
        {
            mp[ele]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto &ele : mp)
        {
            pq.push({-1 * (ele.second), ele.first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> res;

        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};