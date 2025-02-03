class Solution {
private:
    int func(string &s, int n, vector<int>&dp)
    {
        if(s[0]=='0') 
        {
            return 0;
        }

        dp[n]=1;

        int count = 0;

        string str = "";

        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='0')
            {
                dp[i]=0;
                continue;
            }

            dp[i]=dp[i+1];

            if(i+1<n) 
            {
                int twoDigit=stoi(s.substr(i, 2));

                if(twoDigit>=10 && twoDigit<=26) 
                {
                    dp[i]+=dp[i+2];
                }
            }
        }

        return dp[0];
    }
public:
    int numDecodings(string s) {
        int n = s.length();

        vector<int>dp(n+1, 0);

        int count = func(s, n, dp);

        for(auto it: dp)
        {
            cout<<it<<" ";
        }
        cout<<endl;

        return count;
    }
};