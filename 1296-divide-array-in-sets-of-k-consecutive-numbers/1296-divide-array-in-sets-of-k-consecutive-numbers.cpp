class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();

        if(n%k)
        {
            return false;
        }

        map<int, int>mp;

        for(auto it: nums)
        {
            mp[it]++;
        }

        for(auto it=mp.begin(); it!=mp.end();)
        {
            if(it->second>0)
            {
                for(int i=0; i<k; i++)
                {
                    if(mp[it->first+i]>0)
                    {
                        mp[it->first+i]--;
                    }
                    else return false;
                }
            }
            else it++;
        }

        return true;
    }
};