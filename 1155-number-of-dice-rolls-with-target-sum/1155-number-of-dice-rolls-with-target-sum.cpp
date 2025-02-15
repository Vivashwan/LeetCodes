class Solution {
private: 
    int MOD=1e9+7;
    int func(int n, int k, int target, vector<vector<int>>&dp)
    {
        dp[0][0]=1;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=target; j++)
            {
                int count=0;

                for(int val=1; val<=k; val++)
                {
                    if(val<=j)
                    {
                        count=(count+dp[i-1][j-val])%MOD;
                    }
                }

                dp[i][j] = count;
            }
        }

        return dp[n][target];
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
        return func(n, k, target, dp);
    }
};