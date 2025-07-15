class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();

        if(n%2==1)
        {
            return {};
        }

        sort(changed.begin(), changed.end());
        unordered_map<int, int>mp;

        for(auto it: changed)
        {
            mp[it]++;
        }

        vector<int>res;

        for(auto it: changed)
        {
            if(mp[it])
            {
                if(mp[it*2]==0)
                {
                    return {};
                }

                mp[it]--;
                mp[it*2]--;
                res.push_back(it);
            }
        }

        return res;
    }
};