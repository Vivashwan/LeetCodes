class MyHashMap {
private:
    static const int BUCKETS=1009;
    vector<vector<pair<int, int>>>table;

    int hash(int key)
    {
        return key%BUCKETS;
    }

public:
    MyHashMap() {
        table.resize(BUCKETS);
    }
    
    void put(int key, int value) {
        int loc=hash(key);

        for(auto& it: table[loc])
        {
            if(it.first==key)
            {
                it.second=value;
                return;
            }
        }

        table[loc].emplace_back(key, value);
    }
    
    int get(int key) {
        int b=hash(key);

        for(auto &p: table[b])
        {
            if(p.first==key)
            { 
                return p.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int b=hash(key);
        auto &bucket=table[b];

        for(auto it=bucket.begin(); it!=bucket.end(); it++)
        {
            if(it->first==key)
            {
                bucket.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */