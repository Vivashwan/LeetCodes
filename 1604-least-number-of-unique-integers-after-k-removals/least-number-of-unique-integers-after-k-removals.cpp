class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_map<int, int>mp;

        for(auto it: arr)
        {
            mp[it]++;
        }

        if(k==0)
        {
            return mp.size();
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }

        while(!pq.empty() && k!=0)
        {
            auto it = pq.top();

            int count = it.first;

            if(count<=k)
            {
                k-= count;
                pq.pop();
            }
            else
            {
                it.first-=k;
                k=0;
                break;
            } 
        }

        return pq.size();
    }
};