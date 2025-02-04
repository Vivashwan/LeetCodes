class Solution {
private:
    int func(int n, vector<int>& dp) 
    {
        for(int i = 2; i <= n; i++) 
        {  
            int maxi = -1;
            for(int j = 1; j < i; j++) 
            { 
                int product = max(j * (i - j), j * dp[i - j]);
                maxi = max(maxi, product);
            }
            dp[i] = maxi; 
        }
        return dp[n]; 
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        return func(n, dp);
    }
};
