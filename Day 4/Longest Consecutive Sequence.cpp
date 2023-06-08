class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        // m1 nlogn
        // m2
        // hashmap

        int n = nums.size();
        unordered_set<int> mp(nums.begin(), nums.end());
        int mx = 0;
        for (auto &ele : mp)
        {
            int val = ele;
            if (mp.count(val - 1))
                continue;
            int ct = 1;
            val += 1;
            while (mp.count(val))
            {
                val++;
                ct++;
            }
            mx = max(mx, ct);
        }
        return mx;
    }
};