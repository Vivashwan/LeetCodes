class Solution {
private:
    int func(vector<int>&piles, int n, int start, int end, bool alice, vector<vector<vector<int>>>&dp)
    {
        if(start>end)
        {
            return alice?INT_MIN:INT_MAX;
        }

        if(dp[start][end][alice]!=-1)
        {
            return dp[start][end][alice];
        }

        int aliceStones=0, bobStones=0;

        if(alice)
        {
            aliceStones=max(piles[start]+func(piles, n, start+1, end, 0, dp), piles[end]+func(piles, n, start, end-1, 0, dp));
        }
        else bobStones=min(piles[start]+func(piles, n, start+1, end, 1, dp), piles[end]+func(piles, n, start, end-1, 1, dp));

        return dp[start][end][alice] = aliceStones>bobStones;
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));

        return func(piles, n, 0, n-1, 1, dp);
    }
};