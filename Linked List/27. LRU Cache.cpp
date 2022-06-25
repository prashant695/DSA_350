// https://leetcode.com/problems/lru-cache/

class LRUCache
{
public:
    int max_size;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    void change(int key, int value)
    {
        auto it = mp[key];
        l.erase(it);

        l.push_front({key, value});
        mp[key] = l.begin();
    }

    LRUCache(int capacity)
    {
        max_size = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        int val = (*mp[key]).second;
        change(key, val);

        return val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
            change(key, value);
        else
        {
            l.push_front({key, value});
            mp[key] = l.begin();

            if (mp.size() > max_size)
            {
                mp.erase(l.back().first);
                l.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */