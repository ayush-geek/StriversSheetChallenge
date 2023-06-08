class Solution
{
public:
    void merge(vector<int> &nums, int l, int mid, int r)
    {
        int right = mid + 1;
        int low = l;
        while (l <= mid && right <= r)
        {
            if (nums[l] <= nums[right])
            {
                tmp.push_back(nums[l]);
                l++;
            }
            else
            {
                tmp.push_back(nums[right]);
                right++;
            }
        }

        while (l <= mid)
        {
            tmp.push_back(nums[l]);
            l++;
        }

        while (right <= r)
        {
            tmp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= r; i++)
        {
            nums[i] = tmp[i - low];
        }
    }

    int countPairs(vector<int> &nums, int l, int mid, int r)
    {
        int right = mid + 1;
        vector<int> tmp;
        int low = l;
        int ct = 0;
        while (l <= mid)
        {
            while (right <= r && (long long)nums[l] > (long long)2 * nums[right])
            {
                right++;
            }

            ct += (right - (mid + 1));
            l++;
        }

        return ct;
    }

    int mergesort(vector<int> &nums, int l, int r)
    {
        int ct = 0;
        if (l >= r)
            return ct;
        int mid = (l + r) / 2;

        ct += mergesort(nums, l, mid);
        ct += mergesort(nums, mid + 1, r);

        ct += countPairs(nums, l, mid, r);
        merge(nums, l, mid, r);

        return ct;
    }

    int reversePairs(vector<int> &nums)
    {

        return mergesort(nums, 0, nums.size() - 1);
    }
};