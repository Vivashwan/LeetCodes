class Solution {
private:
    int func(vector<int>&prices, int n, vector<vector<vector<int>>>&dp)
    {
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int bought=0; bought<2; bought++)
            {
                for(int trans=1; trans<3; trans++)
                {
                    int profit;

                    if(bought==false)
                    {
                        profit = max(dp[ind+1][0][trans], dp[ind+1][1][trans]-prices[ind]);
                    }
                    else
                    {
                        profit = max(dp[ind+1][1][trans], prices[ind]+dp[ind+1][0][trans-1]);
                    }

                    dp[ind][bought][trans] = profit;
                }
            }
        }

        return dp[0][0][2];

    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(2+1, 0)));

        return func(prices, n, dp);
    }
};