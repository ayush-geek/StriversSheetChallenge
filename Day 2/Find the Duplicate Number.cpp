class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        // m1 map/set
        // m2 sort
        // m3 inplace  by swapping in actual place sine only -ve number

        for (int i = 0; i < nums.size(); i++)
        {
            int val = abs(nums[i]);

            if (nums[val - 1] < 0)
            {
                return abs(nums[i]);
            }
            else
            {
                nums[val - 1] = -1 * nums[val - 1];
            }
        }

        return -1;
    }
};