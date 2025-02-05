class Solution {
private:
    int func(vector<int>&prices, int n, int ind, int fee, bool bought, vector<vector<int>>&dp)
    {
        if(ind>=n)
        {
            return 0;
        }

        if(dp[ind][bought]!=-1)
        {
            return dp[ind][bought];
        }

        int profit = 0;

        if(bought==false)
        {
            profit = max(func(prices, n, ind+1, fee, true, dp)-prices[ind], func(prices, n, ind+1, fee, false, dp));
        }      
        else
        {
            profit = max(func(prices, n, ind+1, fee, false, dp)+prices[ind]-fee, func(prices, n, ind+1, fee, true, dp));
        }  

        return dp[ind][bought] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>>dp(n, vector<int>(2, -1));

        return func(prices, n, 0, fee, false, dp);
    }
};