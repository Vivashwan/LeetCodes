class Solution {
private:
    bool func(string& s1, string& s2, string& s3, int n, int m, int l, int ind1, int ind2, int ind3, vector<vector<vector<int>>>&dp)
    {
        if(ind3>=l)
        {
            return true;
        }

        if(dp[ind1][ind2][ind3]!=-1)
        {
            return dp[ind1][ind2][ind3];
        }

        bool res=false;

        if(ind1<n && s3[ind3]==s1[ind1])
        {
            res=res||func(s1, s2, s3, n, m, l, ind1+1, ind2, ind3+1, dp);
        }

        if(ind2<m && s3[ind3]==s2[ind2])
        {
            res=res||func(s1, s2, s3, n, m, l, ind1, ind2+1, ind3+1, dp);
        }

        return dp[ind1][ind2][ind3] = res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), l = s3.length();

        if(n+m != l)
        { 
            return false; 
        }

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(m+1, vector<int>(l+1, -1)));

        return func(s1, s2, s3, n, m, l, 0, 0, 0, dp);
    }
};