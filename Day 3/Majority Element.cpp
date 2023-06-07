class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        // Boyce moore voting algo

        int ct = 1;
        int mxe = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] != mxe)
                ct--;
            else
                ct++;

            if (ct == 0)
            {
                mxe = nums[i];
                ct++;
            }
        }
        return mxe;
    }
};