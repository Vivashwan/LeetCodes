class Solution {
private:
    int func(vector<int>&coins, int n, int amount, int ind, vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 1;
        }

        if(ind==n-1)
        {
            if(amount%coins[ind]==0)
            {
                return 1;
            }
            else return 0;
        }

        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }

        int notPick = func(coins, n, amount, ind+1, dp);

        int pick = 0;
        if (amount >= coins[ind]) 
        {
            pick = func(coins, n, amount - coins[ind], ind, dp);
        }

        return dp[ind][amount] = pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        return func(coins, n, amount, 0, dp);
    }
};