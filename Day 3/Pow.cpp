class Solution
{
public:
    map<pair<double, int>, double> dp;
    double myPow(double x, int n)
    {

        // pow (2,5)
        //  2*pow(2,2)*pow(2,2)

        // pow(2,6)
        // pow(2,3)* pow(2,3)
        // 2*pow(2,1)*pow(2,1)
        if (dp.find({x, n}) != dp.end())
            return dp[{x, n}];

        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;

        double ans = myPow(x, n / 2) * myPow(x, n / 2);
        int z = abs(n);
        if (z % 2 == 1 && n > 0)
            return dp[{x, n}] = x * ans;
        else if (z % 2 == 1)
            return dp[{x, n}] = (1 / x) * ans;
        else
            return dp[{x, n}] = ans;
    }
};