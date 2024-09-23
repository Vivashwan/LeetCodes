class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>>mp;

        for(auto it: logs)
        {
            mp[it[0]].insert(it[1]);
        }

        vector<int>res(k, 0);

        unordered_map<int, int>mp1;

        for(auto it: mp)
        {
            if(it.second.size()<=k)
            {
                mp1[it.second.size()]++;
            }
        }

        for(auto it: mp1)
        {
            res[it.first-1] = it.second;
        }

        return res;
    }
};