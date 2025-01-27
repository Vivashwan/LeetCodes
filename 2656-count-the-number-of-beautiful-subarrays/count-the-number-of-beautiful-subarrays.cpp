class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long res = 0, val = 0;
        int n = nums.size();

        unordered_map<long long, long long>mp;

        mp[0]++;

        for(int i=0; i<n; i++)
        {
            val^=nums[i];

            if(mp[val])
            {
                res+=mp[val];
            }

            mp[val]++;
        }

        return res;
    }
};