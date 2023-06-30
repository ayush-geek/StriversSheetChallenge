#include <bits/stdc++.h>

struct Node
{
    Node *links[26];
    int ew = 0;
    int cp = 0;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *nd)
    {
        links[ch - 'a'] = nd;
    }

    void increaseEnd()
    {
        ew++;
    }

    void increasePrefix()
    {
        cp++;
    }

    void reduceEnd()
    {
        ew--;
    }

    void reducePrefix()
    {
        cp--;
    }
    int getEnd()
    {
        return ew;
    }
    int getPrefix()
    {
        return cp;
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

    void insert(string &words)
    {

        Node *node = root;
        for (int i = 0; i < words.size(); i++)
        {
            if (!node->containsKey(words[i]))
            {
                node->put(words[i], new Node());
            }

            node = node->get(words[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &words)
    {
        Node *node = root;
        for (int i = 0; i < words.size(); i++)
        {
            if (node->containsKey(words[i]))
            {
                node = node->get(words[i]);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &words)
    {
        Node *node = root;
        for (int i = 0; i < words.size(); i++)
        {
            if (node->containsKey(words[i]))
            {
                node = node->get(words[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string &words)
    {
        Node *node = root;

        for (int i = 0; i < words.size(); i++)
        {
            if (node->containsKey(words[i]))
            {
                node = node->get(words[i]);
                node->reducePrefix();
            }
        }
        node->reduceEnd();
    }
};
