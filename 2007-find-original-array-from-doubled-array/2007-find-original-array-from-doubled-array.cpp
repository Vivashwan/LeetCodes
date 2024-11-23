class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        if(n%2==1)
        {
            return {};
        }

        vector<int>res;

        sort(changed.begin(), changed.end());

        unordered_map<int, int>mp;

        for(auto it: changed)
        {
            mp[it]++;
        }

        for(auto it: changed)
        {
            if(mp[it])
            {
                if(mp[it*2]==0)
                {
                    return {};
                }

                res.push_back(it);

                mp[it]--;
                mp[it*2]--;
            }
        }

        return res;
    }
};