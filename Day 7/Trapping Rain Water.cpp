class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        vector<int> pref(n, 0);
        vector<int> suf(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                pref[i] = height[i];
            else
            {
                pref[i] = max(height[i - 1], pref[i - 1]);
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                suf[i] = height[i];
            else
            {
                suf[i] = max(height[i + 1], suf[i + 1]);
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            int z = min(pref[i], suf[i]) - height[i];

            if (z > 0)
                ans += z;
        }
        return ans;
    }
};