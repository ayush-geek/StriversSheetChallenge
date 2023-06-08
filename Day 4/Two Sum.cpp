class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // m1
        // brue force

        // m2
        // sort 2 pointers
        // nlogn time

        // m3
        // hashmap
        //  linear time and linear spcae

        unordered_map<int, int> mp;
        int k = 0;
        for (auto &ele : nums)
        {
            if (mp.count(target - ele))
            {
                return {mp[target - ele], k};
            }

            mp[ele] = k;

            k++;
        }
        return {-1, -1};
    }
};