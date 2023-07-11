class LFUCache
{
private:
    int cap;
    int mnf; // minimum freq

    struct Node
    {
        int value;
        int frequency;
        list<int>::iterator itr;
    };

    // key , { value , frequency , iterator to the frequency in the list}
    unordered_map<int, Node> cache;

    // freq keys
    unordered_map<int, list<int>> fm;

public:
    LFUCache(int capacity)
    {
        cap = capacity;
        mnf = 0;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        int f = cache[key].frequency;
        int v = cache[key].value;
        auto it = cache[key].itr;

        fm[f].erase(it);
        cache[key].frequency += 1;
        fm[cache[key].frequency].push_back(key);
        cache[key].itr = --fm[cache[key].frequency].end();

        if (fm[mnf].empty())
            mnf++;
        return v;
    }

    void put(int key, int value)
    {

        int cur = get(key);
        if (cur != -1)
        {
            cache[key].value = value;
            return;
        }

        if (cache.size() == cap)
        {
            // if mnf has size 1 delete that
            // else
            // like lru
            // since we are pushing back,so can delete front/Begin
            auto del = fm[mnf].begin();
            int key_del = *del;
            cache.erase(key_del);
            fm[mnf].erase(del);
        }

        // By default f=1 for new element
        fm[1].push_back(key);
        cache[key] = {value, 1, --fm[1].end()};
        mnf = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */