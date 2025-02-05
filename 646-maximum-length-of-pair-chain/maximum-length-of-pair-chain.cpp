class Solution {
private:
    static bool myCmp(const vector<int>&a, const vector<int>&b)
    {
        return a[1]<b[1];
    }

    int func(vector<vector<int>>&pairs, int n, int ind, int prev, vector<vector<int>>&dp)
    {
        if(ind==n)
        {
            return 0;
        }

        if(dp[ind][prev+1]!=-1)
        {
            return dp[ind][prev+1];
        }

        int pick = 0;

        if(prev==-1 || pairs[prev][1]<pairs[ind][0])
        {
            pick = 1+func(pairs, n, ind+1, ind, dp);
        }

        int notPick = 0+func(pairs, n, ind+1, prev, dp);

        return dp[ind][prev+1] = max(pick, notPick);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end(), myCmp);

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return func(pairs, n, 0, -1, dp);
    }
};