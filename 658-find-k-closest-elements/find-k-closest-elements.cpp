class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;

        map<int, vector<int>>mp;

        for(auto it: arr)
        {
            mp[abs(it-x)].push_back(it);
        }

        for(auto u: mp)
        {
            auto v=u.second;

            for(auto it: v)
            {
                if(k!=0)
                {
                    res.push_back(it);
                    k--;
                }
                else break;
            }

            if(k==0)
            {
                break;
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};