class Solution {
private:
    static bool myCmp(const vector<int>&a, const vector<int>&b)
    {
        return a[1]<b[1];
    }

    int func(vector<vector<int>>&pairs, int n, vector<vector<int>>&dp)
    {
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int prev=ind-1; prev>=-1; prev--)
            {
                int pick=0;

                if(prev==-1 || pairs[prev][1]<pairs[ind][0])
                {
                    pick = 1+dp[ind+1][ind+1];
                }

                int notPick = 0+dp[ind+1][prev+1];

                dp[ind][prev+1] = max(pick, notPick);
            }
        }

        return dp[0][0];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end(), myCmp);

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        return func(pairs, n, dp);
    }
};