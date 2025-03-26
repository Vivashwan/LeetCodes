class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>mp;
        priority_queue<pair<int, char>>pq;

        for(auto it: s)
        {
            mp[it]++;
        }

        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }

        string res="";

        while(pq.size()>1)
        {
            auto u=pq.top(); pq.pop();
            auto v=pq.top(); pq.pop();

            res+=u.second; res+=v.second;

            u.first--, v.first--;

            if(u.first>0)
            {
                pq.push(u);
            }

            if(v.first>0)
            {
                pq.push(v);
            }
        }

        if(!pq.empty())
        {
            if(pq.top().first>1)
            {
                return "";
            }
            else 
            {
                res+=pq.top().second;
                pq.pop();
            }
        }

        return res;
    }
};