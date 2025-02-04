class Solution {
private:
    int func(vector<int>&coins, int n, int amount, vector<vector<int>>&dp)
    {
        for(int i=0; i<=n; i++)
        {
            dp[i][0]=0;
        }

        for(int ind=n-1; ind>=0; ind--)
        {
            for(int val=0; val<=amount; val++)
            {
                int pick = 1e9;
                int notPick = dp[ind+1][val];

                if(val>=coins[ind])
                {
                    pick = 1+dp[ind][val-coins[ind]];
                }

                dp[ind][val] = min(pick, notPick);
            }

        }

        return dp[0][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n+1, vector<int>(amount+1, 1e9));

        int ans = func(coins, n, amount, dp);

        return ans>=1e9?-1:ans;      
    }
};