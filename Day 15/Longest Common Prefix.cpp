class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        string tmp = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            for (int j = 0; j < min(strs[i].size(), tmp.size()); j++)
            {
                if (strs[i][j] != tmp[j])
                {
                    tmp = tmp.substr(0, j);
                    break;
                }
            }
            if (tmp.size() > strs[i].size())
                tmp = strs[i];
        }

        return tmp;
    }
};