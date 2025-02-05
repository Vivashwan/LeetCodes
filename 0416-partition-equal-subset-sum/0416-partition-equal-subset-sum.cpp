class Solution {
private:
    bool func(vector<int>&nums, int n, int ind, int amount, vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return true;
        }

        if(ind>=n || amount<0)
        {
            return false;
        }

        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }

        bool pick = func(nums, n, ind+1, amount-nums[ind], dp);
        bool notPick = func(nums, n, ind+1, amount, dp);

        return dp[ind][amount] = pick||notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total%2!=0)
        {
            return false;
        }

        vector<vector<int>>dp(n, vector<int>((total/2)+1, -1));

        return func(nums, n, 0, total/2, dp);
    }
};