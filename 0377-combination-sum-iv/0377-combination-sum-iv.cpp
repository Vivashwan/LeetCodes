class Solution {
private:
    int func(vector<int>&nums, int target, vector<int>&dp)
    {
        dp[0]=1;

        for(int val=1; val<=target; val++)
        {
            long long res=0;

            for(auto it: nums)
            {
                if(it<=val)
                {
                    res+=dp[val-it];
                }
            }

            dp[val] = res;
        }

        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1, 0);
        return func(nums, target, dp);
    }
};