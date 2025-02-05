class Solution {
private:
    int func(vector<int>&nums, int n, unordered_map<int, vector<int>>&mp, vector<int>&dp)
    {
        for(int ind=n-1; ind>=0; ind--)
        {
            int lastInd = mp[nums[ind]].back();

            if(mp[nums[ind]+1].size()>0)
            {
                lastInd = mp[nums[ind]+1].back();
            }

            int pick = nums[ind]*mp[nums[ind]].size()+dp[lastInd+1];
            int notPick = dp[ind+1];

            dp[ind] = max(pick, notPick);
        }

        return dp[0];
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

        vector<int>dp(n+1, 0);

        return func(nums, n, mp, dp);
    }
};