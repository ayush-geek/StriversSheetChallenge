class Solution
{
public:
    int partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[r];
        int p = l;

        for (int i = l; i < r; i++)
        {
            if (nums[i] < pivot)
            {
                swap(nums[p++], nums[i]);
            }
        }

        swap(nums[p], nums[r]);
        return p;
    }

    int findKthLargest(vector<int> &nums, int k)
    {

        // Quck slect
        int i = 0;
        int j = nums.size() - 1;
        k = nums.size() - k;

        while (1)
        {
            int idx = partition(nums, i, j);

            if (idx == k)
                return nums[k];
            else if (idx < k)
                i = idx + 1;
            else
                j = idx - 1;
        }

        return nums[k];
    }
};