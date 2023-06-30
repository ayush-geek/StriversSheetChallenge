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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */