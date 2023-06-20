class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        int n = haystack.size();
        int m = needle.size();

        if (n < m)
            return -1;
        vector<int> lps = kmp(needle);

        int i = 0;
        int j = 0;

        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }

            if (j == m)
                return i - m;
        }

        return -1;
    }

    vector<int> kmp(string needle)
    {
        int j = 0;
        int n = needle.size();
        vector<int> lps(n, 0);
        int i = 1;
        while (i < n)
        {
            if (needle[i] == needle[j])
            {
                lps[i++] = j + 1;
                j++;
            }
            else
            {
                if (j == 0)
                    lps[i++] = 0;
                else
                    j = lps[j - 1];
            }
        }
        return lps;
    }
};