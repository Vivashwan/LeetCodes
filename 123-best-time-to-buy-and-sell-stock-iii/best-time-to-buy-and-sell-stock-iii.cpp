class Solution {
private:
    int func(vector<int>&prices, int n, int ind, bool bought, int trans, vector<vector<vector<int>>>&dp)
    {
        if(ind==n || trans==0)
        {
            return 0;
        }

        if(dp[ind][bought][trans]!=-1)
        {
            return dp[ind][bought][trans];
        }

        int profit;

        if(bought==false)
        {
            profit = max(func(prices, n, ind+1, false, trans, dp), func(prices, n, ind+1, true, trans, dp)-prices[ind]);
        }
        else
        {
            profit = max(func(prices, n, ind+1, true, trans, dp), prices[ind]+func(prices, n, ind+1, false, trans-1, dp));
        }

        return dp[ind][bought][trans] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(2+1, -1)));

        return func(prices, n, 0, false, 2, dp);
    }
};