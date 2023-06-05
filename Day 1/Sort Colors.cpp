class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // sort colors
        // Dutch national flag Algo

        int n = nums.size();

        int i = 0;
        int j = n - 1;
        int p = 0;

        while (i <= j)
        {
            if (nums[i] == 2)
            {
                swap(nums[i], nums[j]);
                j--;
            }
            else if (nums[i] == 0)
            {
                swap(nums[i], nums[p]);
                p++;
                i++;
            }
            else
            {
                i++;
            }
        }
    }
};