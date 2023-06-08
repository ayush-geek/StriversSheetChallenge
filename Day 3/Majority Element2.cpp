class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        // m1 Intuitive Hashmap
        // m2 Extended Boyce moore
        int ct1 = 0;
        int ct2 = 0;

        int mx1 = INT_MIN;
        int mx2 = INT_MIN;

        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            if (ct1 == 0 && nums[i] != mx2)
            {
                mx1 = nums[i];
                ct1++;
            }
            else if (nums[i] == mx1)
            {
                ct1++;
            }
            else if (ct2 == 0 && mx1 != nums[i])
            {
                mx2 = nums[i];
                ct2++;
            }
            else if (nums[i] == mx2)
            {
                ct2++;
            }
            else
            {
                ct1--;
                ct2--;
            }
        }

        int fc1 = 0, fc2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == mx1)
                fc1++;
            if (nums[i] == mx2)
                fc2++;
        }
        if (fc1 <= n / 3 && fc2 <= n / 3)
            return {};
        else if (fc2 <= n / 3)
            return {mx1};
        else if (fc1 <= n / 3)
            return {mx2};
        else
            return {mx1, mx2};
    }
};