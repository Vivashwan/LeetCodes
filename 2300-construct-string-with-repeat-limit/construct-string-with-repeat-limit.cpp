class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int>mp;

        for(auto it: s)
        {
            mp[it]++;
        }

        priority_queue<pair<char, int>>pq;

        for(auto it: mp)
        {
            pq.push({it.first, it.second});
        }

        string res;

        while(!pq.empty())
        {
            auto [ch1, count1]=pq.top();
            pq.pop();

            int mini=min(repeatLimit, count1);
            res.append(mini, ch1);
            count1-=mini;

            if(count1>0)
            {
                if(pq.empty())
                {
                    break;
                }

                auto [ch2, count2]=pq.top();
                pq.pop();

                res.push_back(ch2);
                count2--;

                if(count2>0)
                {
                    pq.push({ch2, count2});
                }

                pq.push({ch1, count1});
            }
        }

        return res;
    }
};