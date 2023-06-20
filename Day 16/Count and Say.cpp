class Solution
{
public:
    string count(string s)
    {
        int n = s.size();
        int ct = 1;
        char z = s[0];
        string res;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == z)
            {
                ct++;
            }
            else
            {
                res += to_string(ct);
                res.push_back(z);

                z = s[i];
                ct = 1;
            }
        }

        res += to_string(ct);
        res.push_back(z);

        return res;
    }
    string solve(int n)
    {
        if (n == 1)
            return "1";

        return count(solve(n - 1));
    }

    string countAndSay(int n)
    {
        // nyc

        return solve(n);
    }
};