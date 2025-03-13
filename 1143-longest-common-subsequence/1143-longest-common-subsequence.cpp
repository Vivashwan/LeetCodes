class Solution {
private:
    int func(string &text1, string &text2, int n, int m, vector<vector<int>>&dp)
    {
        for(int ind1=1; ind1<=n; ind1++)
        {
            for(int ind2=1; ind2<=m; ind2++)
            {
                int res=0;

                if(text1[ind1-1]==text2[ind2-1])
                {
                    res=1+dp[ind1-1][ind2-1];
                }
                else res=max({res, dp[ind1][ind2-1], dp[ind1-1][ind2]});

                dp[ind1][ind2] = res;
            }
        }

        return dp[n][m];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        return func(text1, text2, n, m, dp);
    }
};