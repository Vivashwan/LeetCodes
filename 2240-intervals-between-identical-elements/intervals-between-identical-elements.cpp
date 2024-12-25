class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, pair<long, long>>mp;

        vector<long long>res(n);

        for(int i=0; i<n; i++)
        {
            auto [count, val] = mp[arr[i]];

            if(count==0)
            {
                mp[arr[i]] = {1, i};
                continue;
            }

            res[i] = i*count-val;
            mp[arr[i]].second+=i;
            mp[arr[i]].first++;
        }

        mp.clear();

        for(int i=n-1; i>=0; i--)
        {
            auto [count, val] = mp[arr[i]];

            if(count==0)
            {
                mp[arr[i]] = {1, i};
                continue;
            }

            res[i] += val-i*count;
            mp[arr[i]].second+=i;
            mp[arr[i]].first++;
        }

        return res;
    }
};