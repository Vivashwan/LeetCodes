class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>>mp;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())
        { 
            return "";
        }

        auto& values=mp[key];

        int left=0, right=values.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(values[mid].first==timestamp)
            {
                return values[mid].second;
            } 
            else if(values[mid].first<timestamp)
            {
                left=mid+1;
            } 
            else
            {
                right=mid-1;
            }
        }

        if(right<0)
        { 
            return "";
        }

        return values[right].second;   
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */