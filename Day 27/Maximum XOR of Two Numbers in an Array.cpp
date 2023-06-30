
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
    int findMaximumXOR(vector<int> &A)
    {
        Trie tt;

        for (int i = 0; i < A.size(); i++)
        {
            tt.insert(A[i]);
        }

        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            ans = max(ans, tt.findMax(A[i]));
        }
        return ans;
    }
};