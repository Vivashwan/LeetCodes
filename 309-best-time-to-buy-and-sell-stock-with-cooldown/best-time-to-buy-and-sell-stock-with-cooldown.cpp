class Solution {
private:
    int func(vector<int>&prices, int n, vector<vector<int>>&dp)
    {
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int bought=0; bought<=1; bought++)
            {
                int profit;

                if(bought==0)
                {
                    profit = max(dp[ind+1][1]-prices[ind], dp[ind+1][0]);
                }
                else
                {
                    profit = max(dp[ind+2][0]+prices[ind], dp[ind+1][1]);
                }

                dp[ind][bought] = profit;
            }
        }

        return dp[0][0];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>dp(n+2, vector<int>(2, 0));

        return func(prices, n, dp);
    }
};