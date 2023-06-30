#include <bits/stdc++.h>

struct Node
{

    Node *links[26];
    bool flag;

    bool containWord(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void putWord(char ch, Node *nd)
    {
        links[ch - 'a'] = nd;
    }

    Node *getWord(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag == true;
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

    void insert(string word)
    {
        Node *tmp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!tmp->containWord(word[i]))
            {
                tmp->putWord(word[i], new Node());
            }
            tmp = tmp->getWord(word[i]);
        }

        tmp->setEnd();
    }

    bool search(string word)
    {
        Node *tmp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!tmp->containWord(word[i]))
            {
                return false;
            }
            tmp = tmp->getWord(word[i]);
        }

        if (tmp->isEnd())
            return true;
        return false;
    }

    bool startsWith(string word)
    {
        Node *tmp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!tmp->containWord(word[i]))
            {
                return false;
            }
            tmp = tmp->getWord(word[i]);
        }
        return true;
    }

    bool isComplete(string word)
    {
        Node *tmp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (tmp->containWord(word[i]))
            {
                tmp = tmp->getWord(word[i]);
            }
            else
                return false;
            if (!tmp->isEnd())
                return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie tt;
    for (int i = 0; i < a.size(); i++)
    {
        tt.insert(a[i]);
    }

    // Now chk
    string res = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (tt.isComplete(a[i]))
        {
            if (a[i].size() > res.size())
                res = a[i];
            else if (a[i].size() == res.size())
            {
                res = min(res, a[i]);
            }
        }
    }
    if (res == "")
        return "None";
    return res;
}