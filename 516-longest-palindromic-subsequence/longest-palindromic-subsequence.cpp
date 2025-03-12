class Solution {
private:
    int func(string &s, int n, vector<vector<int>>&dp) 
    {
        for(int l=0; l<n; l++)
        {
            dp[l][l]=1;
        }

        for(int len=2; len<=n; len++) 
        { 
            for(int i=0; i<=n-len; i++) 
            { 
                int j=i+len-1; 

                if(s[i]==s[j])
                {
                    dp[i][j] = 2+dp[i+1][j-1];  
                } 
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[0][n-1];
    }

public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        return func(s, n, dp);
    }
};
