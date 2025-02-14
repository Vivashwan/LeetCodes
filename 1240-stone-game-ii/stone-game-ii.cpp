class Solution {
private:
    int func(vector<int>&piles, int n, int ind, int M, int alice, vector<vector<vector<int>>>&dp)
    {
        if(ind>=n)
        {
            return 0;
        }

        if(dp[ind][M][alice]!=-1)
        {
            return dp[ind][M][alice];
        }

        int res=(alice==1)?INT_MIN:INT_MAX;

        int stones=0;

        for(int X=1; X<=min(2*M, n-ind); X++)
        {
            stones+=piles[ind+X-1];

            if(alice==1)
            {
                res=max(res, stones+func(piles, n, ind+X, max(M,X), 0, dp));
            }
            else res=min(res, func(piles, n, ind+X, max(M,X), 1, dp));
        }

        return dp[ind][M][alice] = res;     
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(201, vector<int>(2, -1)));

        return func(piles, n, 0, 1, 1, dp);
    }
};