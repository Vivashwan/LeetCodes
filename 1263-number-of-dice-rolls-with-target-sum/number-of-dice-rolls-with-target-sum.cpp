class Solution {
private: 
    int MOD=1e9+7;
    int func(int n, int k, int target, vector<vector<int>>&dp)
    {
        if(target==0 && n==0)
        {
            return 1;
        }

        if((target!=0 && n==0) || (target==0 && n!=0))
        {
            return 0;
        }

        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }

        int count=0;

        for(int val=1; val<=k; val++)
        {
            if(val<=target)
            {
                count=(count+func(n-1, k, target-val, dp))%MOD;
            }
        }

        return dp[n][target] = count;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return func(n, k, target, dp);
    }
};