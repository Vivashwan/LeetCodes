class Solution {
private:
    int func(vector<int>&nums, int n, int start, int end, int turn, vector<vector<vector<int>>>&dp)
    {
        if(start==n || end==-1)
        {
            return 0;
        }

        if(start>end)
        {
            return 0;
        }

        if(dp[start][end][turn]!=-1)
        {
            return dp[start][end][turn];
        }

        if(turn==0)
        {
            return dp[start][end][turn] = max(nums[start]+func(nums, n, start+1, end, 1, dp), nums[end]+func(nums, n, start, end-1, 1, dp));
        }
        else
        {
            return dp[start][end][turn] = min(-nums[start]+func(nums, n, start+1, end, 0, dp), -nums[end]+func(nums, n, start, end-1, 0, dp));
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));

        int val = func(nums, n, 0, n-1, 0, dp);

        return val>=0;
    }
};