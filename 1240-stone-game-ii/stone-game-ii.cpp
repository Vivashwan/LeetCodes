class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(201, vector<int>(2, 0)));
        
        for(int ind=n-1; ind>=0; ind--) 
        {
            for(int M=n; M>=1; M--) 
            {
                for(int alice=0; alice<=1; alice++) 
                {
                    int res=(alice==1) ? INT_MIN:INT_MAX;
                    int stones=0;
                    
                    for(int X=1; X<=min(2*M, n-ind); X++) 
                    {
                        stones+=piles[ind+X-1];  

                        if(alice==1) 
                        {
                            res=max(res, stones+dp[ind+X][max(M, X)][0]);
                        } 
                        else 
                        {
                            res=min(res, dp[ind+X][max(M, X)][1]);
                        }
                    }

                    dp[ind][M][alice]=res;
                }
            }
        }
        
        return dp[0][1][1];
    }
};
