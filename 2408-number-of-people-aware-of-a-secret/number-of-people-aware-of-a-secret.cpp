class Solution {
private:
    int MOD=1e9+7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1, 0);
        dp[1]=1;
        long long sharing=0;

        for(int day=2; day<=n; ++day)
        {
            if(day-delay>=1) 
            {
                sharing=(sharing+dp[day-delay])%MOD;
            }

            if(day-forget>=1) 
            {
                sharing=(sharing-dp[day-forget]+MOD)%MOD;
            }

            dp[day]=sharing;
        }

        long long result=0;

        for(int i=n-forget+1; i<=n; i++)
        {
            result=(result+dp[i])%MOD;
        }

        return result;
    }
};
