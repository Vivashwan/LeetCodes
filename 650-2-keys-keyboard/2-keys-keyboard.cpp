class Solution {
private:
    int func(int n, int steps, int val, int copy, vector<vector<int>>&dp)
    {
        if(val>n || steps>n)
        {
            return INT_MAX;
        }

        if(dp[steps][val]!=-1)
        {
            return dp[steps][val];
        }

        if(val==n)
        {
            return steps;
        }

        return dp[steps][val] = min(func(n, steps+1, val+copy, copy, dp), func(n, steps+2, 2*val, val, dp));
    }
public:
    int minSteps(int n) {
        if(n==1)
        {
            return 0;
        }

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return func(n, 1, 1, 1, dp);
    }
};