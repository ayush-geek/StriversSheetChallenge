class Solution
{
public:
    string reverseWords(string s)
    {

        int i = 0;

        int ct = 0;
        while (s[i] == ' ')
        {
            ct++;
            i++;
        }
        s.erase(0, ct);

        int j = s.size() - 1;
        ct = 0;

        while (s[j] == ' ')
        {
            j--;
            ct++;
        }
        // cout<<ct<<endl;
        s.erase(j + 1, ct);

        j = 0;
        for (int k = 0; k <= s.size();)
        {
            if (s[k] == ' ')
            {
                reverse(s.begin() + j, s.begin() + k);
                // cout<<s<<endl;
                int l = k + 1;
                int c = 0;
                while (s[l] == ' ')
                {
                    l++;
                    c++;
                }

                s.erase(k + 1, c);
                j = k + 1;
            }

            else if (k == s.size())
            {
                reverse(s.begin() + j, s.begin() + k);
            }

            k++;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};