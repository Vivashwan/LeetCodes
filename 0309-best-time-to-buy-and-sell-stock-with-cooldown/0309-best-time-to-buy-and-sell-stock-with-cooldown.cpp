class Solution {
private:
    int func(vector<int>&prices, int n, int ind, bool bought, vector<vector<int>>&dp)
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
            profit = max(func(prices, n, ind+1, true, dp)-prices[ind], func(prices, n, ind+1, false, dp));
        }      
        else
        {
            profit = max(func(prices, n, ind+2, false, dp)+prices[ind], func(prices, n, ind+1, true, dp));
        }  

        return dp[ind][bought] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>dp(n, vector<int>(2, -1));

        return func(prices, n, 0, false, dp);
    }
};