class Solution {
private:
    int func(vector<int>& piles, int n, vector<vector<vector<int>>>&dp) 
    {
        for(int i=0; i<n; i++) 
        {
            dp[i][i][1]=piles[i];
            dp[i][i][0]=0; 
        }
        
        for(int start=n-1; start>=0; start--)
        {
            for(int end=start; end<n; end++) 
            {
                for(int alice=0; alice<2; alice++) 
                {
                    int aliceStones=0, bobStones=0;

                    int nextStart=(start+1<n) ? dp[start+1][end][0] : 0;
                    int prevEnd=(end-1>=0) ? dp[start][end-1][0] : 0;

                    if(alice) 
                    {
                        aliceStones=max(piles[start]+nextStart, piles[end]+prevEnd);
                    } 
                    else 
                    {
                        nextStart=(start+1<n) ? dp[start+1][end][1] : 0;
                        prevEnd=(end-1>=0) ? dp[start][end-1][1] : 0;
                        bobStones=min(nextStart, prevEnd);
                    }

                    dp[start][end][alice] = alice ? aliceStones:bobStones;
                }
            }
        }

        return dp[0][n-1][1] > dp[0][n-1][0];  
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        return func(piles, n, dp);
    }
};