class Solution {
private:
    bool func(string s, int n, int ind, unordered_set<string>&mp, vector<int>&dp)
    {
        if(ind==n)
        {
            return true;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        if(mp.find(s.substr(ind, n-ind))!=mp.end())
        {
            return true;
        }

        for(int len=1; len<=n; len++)
        {
            string temp=s.substr(ind, len);

            if(mp.find(temp)!=mp.end() && func(s, n, ind+len, mp, dp))
            {
                return true;
            }
        }

        return dp[ind] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string>mp(wordDict.begin(), wordDict.end());

        vector<int>dp(301, -1);

        return func(s, n, 0, mp, dp);
    }
};