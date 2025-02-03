class Solution {
private:
    int func(int n, vector<int>&dp)
    {
        if(n==0)
        {
            return 0;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        int maxim = INT_MAX;

        for(int i=1; i*i<=n; i++)
        {
            maxim = min(maxim, 1+func(n-i*i, dp));
        }

        return dp[n] = maxim;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return func(n, dp);
    }
};