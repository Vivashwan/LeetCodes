class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();

        if(n==1)
        {
            return barcodes;
        }

        vector<int>res;

        unordered_map<int, int>mp;

        for(auto it: barcodes)
        {
            mp[it]++;
        }

        priority_queue<pair<int, int>>pq;

        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }

        while(pq.size()>1)
        {
            auto [occ1, val1]=pq.top(); pq.pop();
            auto [occ2, val2]=pq.top(); pq.pop();

            res.push_back(val1);
            res.push_back(val2);

            occ1--, occ2--;

            if(occ1>0)
            {
                pq.push({occ1, val1});
            }

            if(occ2>0)
            {
                pq.push({occ2, val2});
            }
        }

        if(!pq.empty())
        {
            auto [occ, val]=pq.top();
            pq.pop();

            res.push_back(val);
        }

        return res;
    }
};