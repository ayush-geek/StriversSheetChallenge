class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[0] <= target)
            {
                if (nums[mid] >= nums[0] && nums[mid] < target)
                    l = mid + 1;

                else if (nums[mid] >= nums[0] && nums[mid] > target)
                    h = mid - 1;
                else if (nums[mid] < target)
                {
                    h = mid - 1;
                }
            }

            else
            {
                if (nums[mid] >= nums[0] && nums[mid] > target)
                    l = mid + 1;
                else if (nums[mid] < nums[0] && nums[mid] > target)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return -1;
    }
};