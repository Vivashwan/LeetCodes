class Solution {
private:
    int func(vector<int>&nums, int n, int prev, int curr, vector<vector<int>>&dp)
    {
        if(curr>=n)
        {
            return 0;
        }

        if(dp[prev+1][curr]!=-1)
        {
            return dp[prev+1][curr];
        }

        int res=0;

        if(prev==-1 || nums[curr]>nums[prev])
        {
            res=max(res, 1+func(nums, n, curr, curr+1, dp));
        }

        res=max(res, func(nums, n, prev, curr+1, dp));

        return dp[prev+1][curr] = res;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return func(nums, n, -1, 0, dp);
    }
};