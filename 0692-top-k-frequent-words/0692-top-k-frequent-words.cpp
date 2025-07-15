class Solution {
private:
    static bool myCmp(pair<int,string>&a, pair<int,string>&b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first>b.first;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>mp;

        for(auto it: words)
        {
            mp[it]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(&myCmp)> pq(&myCmp);
        
        for(auto it: mp)
        {
            pq.push({it.second, it.first});

            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<string>v;

        while(!pq.empty())
        {
            v.insert(v.begin(), pq.top().second);
            pq.pop();
        }

        return v;
    }
};