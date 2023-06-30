
struct Node
{

    Node *links[2];

    bool containWord(int ch)
    {
        return links[ch] != NULL;
    }

    void putWord(int ch, Node *nd)
    {
        links[ch] = nd;
    }

    Node *getWord(int ch)
    {
        return links[ch];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *tmp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = num & (1 << i);
            if (bit != 0)
                bit = 1;
            if (!tmp->containWord(bit))
            {
                tmp->putWord(bit, new Node());
            }
            tmp = tmp->getWord(bit);
        }
    }

    int findMax(int num)
    {
        Node *tmp = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = num & (1 << i);
            if (bit != 0)
                bit = 1;
            if (tmp->containWord(1 - bit))
            {
                ans = ans | (1 << i);
                tmp = tmp->getWord(1 - bit);
            }
            else
                tmp = tmp->getWord(bit);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        Trie tt;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);
        }

        vector<int> res(queries.size(), 0);

        sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int k = 0;

        for (auto &ele : queries)
        {
            int a = ele[0], b = ele[1], c = ele[2];
            int ans = 0;
            while (k < nums.size() && nums[k] <= b)
            {
                tt.insert(nums[k++]);
            }

            if (k == 0)
                ans = -1;
            else
                ans = tt.findMax(a);
            res[c] = ans;
        }

        return res;
    }
};