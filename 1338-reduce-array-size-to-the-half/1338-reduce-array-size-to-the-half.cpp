class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int size = n/2;

        unordered_map<int, int>mp;

        for(auto it: arr)
        {
            mp[it]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>>pq;

        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }

        int res=0, count=0;

        while(!pq.empty())
        {
            auto u = pq.top();

            pq.pop();

            res++;

            count+=u.first;

            if(count>=size)
            {
                break;
            }
        }

        return res;
    }
};