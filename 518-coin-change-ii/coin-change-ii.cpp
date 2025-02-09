class Solution {
private:
    int solve(int n, int amount,vector<int> &coins,vector<vector<double>> &dp)
    {
        for(int i=0; i<=amount; i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=1;
            }
            else dp[0][i]=0;
        }
    
        for(int index=1; index<n; index++)
        {
            for(int target=0; target<=amount; target++)
            {
                double notPick=dp[index-1][target];
                double pick=0;
                if(coins[index]<=target)
                {
                    pick=dp[index][target-coins[index]];
                }
                dp[index][target]=notPick+pick;
            }
        }

        return dp[n-1][amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<double>>dp(n,vector<double>(amount+1,0));
        return solve(n,amount,coins,dp);
    }
};