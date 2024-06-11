class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int>mp;

        for(auto it: arr)
        {
            int val = it%k;

            if(val<0)
            {
                val+=k;
            }

            mp[val]++;
        }

        if(mp[0]%2!=0)
        {
            return false;
        }

        for(int i=1; i<=k/2; i++)
        {
            if(mp[i]!=mp[k-i])
            {
                return false;
            }
        }

        return true;
    }
};