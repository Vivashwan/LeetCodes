class Solution {
private:
    int func(vector<int>&nums, int n, unordered_map<int, vector<int>>&mp, int ind, vector<int>&dp)
    {
        if(ind>=n)
        {
            return 0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        int lastInd = mp[nums[ind]].back();

        if(mp[nums[ind]+1].size()>0)
        {
            lastInd = mp[nums[ind]+1].back();
        }

        int pick = nums[ind]*mp[nums[ind]].size()+func(nums, n, mp, lastInd+1, dp);
        int notPick = func(nums, n, mp, ind+1, dp);

        return dp[ind] = max(pick, notPick);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>>mp;

        for(int i=0; i<n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        vector<int>dp(n, -1);

        return func(nums, n, mp, 0, dp);
    }
};