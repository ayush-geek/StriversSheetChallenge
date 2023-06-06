#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &nums, int n)
{
    // Write your code here

    // By Negative Marking
    int d = -1, m = -1;
    for (int i = 0; i < n; i++)
    {
        int val = abs(nums[i]);

        if (nums[val - 1] < 0)
        {
            d = val;
        }
        else
        {
            nums[val - 1] *= -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            m = i + 1;
    }

    return {m, d};
}
