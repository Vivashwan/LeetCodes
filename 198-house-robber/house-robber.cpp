class Solution {
private:
    int func(int ind, int n, vector<int>&nums, vector<int>&dp)
    {
        if(ind>=n)
        {
            return 0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        int pick=0, notPick=0;

        pick = nums[ind]+func(ind+2, n, nums, dp);
        notPick = func(ind+1, n, nums, dp);

        return dp[ind]=max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n, -1);

        return func(0, n, nums, dp);
    }
};