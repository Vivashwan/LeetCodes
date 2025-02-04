class Solution {
private:
    int func(int n, vector<int>&dp)
    {
        int maxi = -1;

        if(n<=1)
        {
            return 0;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        for(int i=1; i<n; i++)
        {
            int product = i*(n-i);
            product = max(product, i*func(n-i, dp));

            maxi = max(maxi, product);
        }

        return dp[n] = maxi;
    }
public:
    int integerBreak(int n) {
        vector<int>dp(n+1, -1);
        return func(n, dp);
    }
};