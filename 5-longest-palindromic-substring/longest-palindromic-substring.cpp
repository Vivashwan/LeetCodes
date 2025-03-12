class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n==1)
        {
            return s;
        }

        vector<vector<bool>>dp(n+1, vector<bool>(n+1, false));

        int start=0, maxLen=1;

        for(int i=0; i<n; i++)
        {
            dp[i][i]=true;
        }

        for(int i=0; i<n-1; i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;

                maxLen=2, start=i;
            }
        }

        for(int len=3; len<=n; len++)
        {
            for(int i=0; i<=n-len; i++)
            {
                int j=i+len-1;

                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=true;

                    maxLen=len, start=i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};