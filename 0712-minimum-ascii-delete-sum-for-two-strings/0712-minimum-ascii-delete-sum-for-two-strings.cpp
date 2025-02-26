class Solution {
private:
    int func(string& s1, string& s2, int n, int m, int ind1, int ind2, vector<vector<int>>&dp)
    {
        for(int i=1; i<=n; i++) 
        {
            dp[i][0]=dp[i-1][0]+int(s1[i-1]);
        }

        for(int j=1; j<=m; j++) 
        {
            dp[0][j]=dp[0][j-1]+int(s2[j-1]);
        }

        int res=0;

        for(int ind1=1; ind1<=n; ind1++)
        {
            for(int ind2=1; ind2<=m; ind2++)
            {
                if(s1[ind1-1]==s2[ind2-1])
                {
                    res=dp[ind1-1][ind2-1];
                }
                else res=min(int(s1[ind1-1])+dp[ind1-1][ind2], int(s2[ind2-1])+dp[ind1][ind2-1]);

                dp[ind1][ind2] = res;
            }
        }

        return dp[n][m];
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(), m=s2.length();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        return func(s1, s2, n, m, 0, 0, dp);
    }
};