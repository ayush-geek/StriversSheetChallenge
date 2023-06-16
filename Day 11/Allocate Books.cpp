#include <bits/stdc++.h>
int solve(vector<int> &A, int B, int mid)
{
    int bk = 1;
    int pg = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > mid)
            return false;

        if (A[i] + pg > mid)
        {
            bk++;
            pg = A[i];
        }
        else
        {
            pg += A[i];
        }
    }

    if (bk > B)
        return false;

    return true;
}

int Solution::books(vector<int> &A, int B)
{

    if (A.size() < B)
        return -1;
    // sort(A.begin(),A.end());
    int l = *min_element(A.begin(), A.end());
    int h = accumulate(A.begin(), A.end(), 0);
    int ans = -1;
    while (l <= h)
    {
        int mid = (l + h) / 2;

        bool z = solve(A, B, mid);

        if (z)
        {
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }

    return ans;
}
