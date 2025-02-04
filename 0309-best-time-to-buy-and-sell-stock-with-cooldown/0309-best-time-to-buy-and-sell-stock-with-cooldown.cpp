class Solution {
private:
    int func(vector<int>&prices, int n)
    {
        vector<int>next1(2, 0), next(2, 0), curr(2, 0);
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int bought=0; bought<=1; bought++)
            {
                int profit;

                if(bought==0)
                {
                    profit = max(next[1]-prices[ind], next[0]);
                }
                else
                {
                    profit = max(next1[0]+prices[ind], next[1]);
                }

                curr[bought] = profit;
            }

            next1 = next;
            next = curr;
        }

        return next[0];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return func(prices, n);
    }
};