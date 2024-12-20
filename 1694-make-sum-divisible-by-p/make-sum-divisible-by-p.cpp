class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        int total = 0;

        for(auto it: nums)
        {
            total=(total+it)%p;
        }

        int rem = total%p;

        if(rem==0)
        {
            return 0;
        }

        unordered_map<int, int>mp;

        mp[0] = -1;

        int res = n, sum = 0;

        for(int i=0; i<n; i++)
        {
            sum = (sum+nums[i])%p;

            int check = (sum-rem+p)%p;

            if(mp.find(check)!=mp.end())
            {
                res = min(res, i - mp[check]);
            }

            mp[sum] = i;
        }

        return res == n ? -1: res;
    }
};