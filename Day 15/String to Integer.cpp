class Solution
{
public:
    int myAtoi(string s)
    {

        int i = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                break;
        }
        int fg = 0;

        if (s[i] == '+' || s[i] == '-')
        {
            if (s[i] == '-')
                fg = 1;
            else
                fg = 0;
            i++;
        }
        long long ans = 0;
        while (i < s.size())
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                ans = ans * 10 + (s[i] - '0');
                if (fg == 0 && ans >= INT_MAX)
                    break;
                if (fg == 1 && -1 * ans <= INT_MIN)
                    break;
            }
            else
                break;
            i++;
        }

        if (fg == 0)
            return min(ans, (long long)INT_MAX);
        else
            return max(-1 * ans, (long long)INT_MIN);
    }
};