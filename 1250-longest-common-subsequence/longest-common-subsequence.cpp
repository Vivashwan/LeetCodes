class Solution {
private:
    int func(string &text1, string &text2, int n, int m, int ind1, int ind2, vector<vector<int>>&dp)
    {
        if(ind1>=n || ind2>=m)
        {
            return 0;
        }

        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }

        int res=0;

        if(text1[ind1]==text2[ind2])
        {
            res=1+func(text1, text2, n, m, ind1+1, ind2+1, dp);
        }
        else res=max({res, func(text1, text2, n, m, ind1+1, ind2, dp), func(text1, text2, n, m, ind1, ind2+1, dp)});

        return dp[ind1][ind2] = res;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

        return func(text1, text2, n, m, 0, 0, dp);
    }
};