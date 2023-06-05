class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // Not this next_permutation(nums.begin(),nums.end());

        // find the 1st decraing num from back
        // nums[i]<nums[i+1];

        int pos = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pos = i;
                break;
            }
        }

        if (pos == -1) // alreday in reverse order
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        else
        {
            // find the pos of  first element just graeter than it
            // sort the remaing
            for (int i = n - 1; i > pos; i--)
            {
                if (nums[i] > nums[pos])
                {

                    swap(nums[i], nums[pos]);
                    sort(nums.begin() + pos + 1, nums.end());
                    break;
                }
            }
        }
    }
};