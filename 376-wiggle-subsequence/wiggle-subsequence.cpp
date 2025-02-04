class Solution {
private:
    int func(vector<int>& nums, int ind, int prev, bool positive, vector<vector<vector<int>>>& dp) 
    {
        if(ind == nums.size()) 
        {
            return 0; 
        }

        if(dp[ind][prev][positive]!=-1)
        {
            return dp[ind][prev][positive];
        }
        
        int pick = 0;

        if((positive && nums[ind] > nums[prev]) || (!positive && nums[ind] < nums[prev])) 
        {
            pick = 1 + func(nums, ind + 1, ind, !positive, dp); 
        }
        
        int notPick = func(nums, ind + 1, prev, positive, dp); 

        return dp[ind][prev][positive] = max(pick, notPick);
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        { 
            return 1;
        }

        vector<vector<vector<int>>>dp;

        dp.resize(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));

        return 1 + max(func(nums, 1, 0, true, dp), func(nums, 1, 0, false, dp)); 
    }
};
