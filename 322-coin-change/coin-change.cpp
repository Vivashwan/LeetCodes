class Solution {
private:
    int func(vector<int>&coins, int n, int ind, int amount, vector<vector<int>>&dp)
    {
        if(amount==0) 
        {
            return 0;  
        }

        if(ind>=n || amount<0) 
        {
            return 1e9;
        }

        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }

        int pick = 1+func(coins, n, ind, amount-coins[ind], dp);
        int notPick = 0+func(coins, n, ind+1, amount, dp);

        return dp[ind][amount] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        int ans = func(coins, n, 0, amount, dp);

        return ans>=1e9?-1:ans;      
    }
};