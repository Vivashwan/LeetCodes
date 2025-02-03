class Solution {
private:
    int func(int n, vector<int>&nums, vector<int>&dp)
    {
        int pick=0, notPick=0;

        for(int ind=n-1; ind>=0; ind--)
        {
            pick = nums[ind] + dp[ind+2];

            notPick = dp[ind+1];

            dp[ind]=max(pick, notPick);
        }

        return dp[0];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+2, 0);

        return func(n, nums, dp);
    }
};