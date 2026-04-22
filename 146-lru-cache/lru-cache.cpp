class LRUCache {
public:
    int cap;
    list<pair<int,int>> dq;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        int val = it->second->second;
        dq.erase(it->second);
        dq.push_front({key, val});
        mp[key] = dq.begin();
        return val;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            dq.erase(it->second);
        } else if ((int)dq.size() == cap) {
            auto last = dq.back();
            mp.erase(last.first);
            dq.pop_back();
        }
        dq.push_front({key, value});
        mp[key] = dq.begin();
    }
};