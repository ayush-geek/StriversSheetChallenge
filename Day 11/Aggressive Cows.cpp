#include <bits/stdc++.h>

bool chk(vector<int> &stalls, int mid, int k)
{
    int cowCount = 1;

    int lastpos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {

        if (stalls[i] - lastpos >= mid)
        {

            cowCount++;

            if (cowCount == k)
            {

                return true;
            }

            lastpos = stalls[i];
        }
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int l = 1;
    int h = stalls.back() - stalls[0];
    int ans = 0;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        bool z = chk(stalls, mid, k);
        //  cout<<mid<<" "<<z<<endl;
        if (z)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return ans;
}