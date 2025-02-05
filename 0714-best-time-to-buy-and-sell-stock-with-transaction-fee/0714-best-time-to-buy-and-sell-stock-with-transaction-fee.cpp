class Solution {
private:
    int func(vector<int>&prices, int n, int fee, vector<vector<int>>&dp)
    {
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int bought=0; bought<=1; bought++)
            {
                int profit = 0;

                if(bought==false)
                {
                    profit = max(dp[ind+1][1]-prices[ind], dp[ind+1][0]);
                }      
                else
                {
                    profit = max(dp[ind+1][false]+prices[ind]-fee, dp[ind+1][1]);
                }  

                dp[ind][bought] = profit;
            }

        }
        
        return dp[0][0];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>>dp(n+1, vector<int>(2, 0));

        return func(prices, n, fee, dp);
    }
};