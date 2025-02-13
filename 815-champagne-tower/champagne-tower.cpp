class Solution {
private:
    double func(int poured, int row, int col, vector<vector<double>>&dp)
    {
        dp[0][0]=(double)poured;

        for(int i=1; i<=row; i++)
        {
            for(int j=0; j<=i; j++)
            {
                double left = 0.0, right = 0.0;
                
                if(j>0) 
                {
                    left=max(0.0, (dp[i-1][j-1]-1)/2.0);
                }

                if(j<i) 
                {
                    right=max(0.0, (dp[i-1][j]-1)/2.0);
                }

                dp[i][j] = left+right;

            }
        }

        return dp[row][col];
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(query_row+1, vector<double>(query_row+1, 0.0));
        return min(1.0, func(poured, query_row, query_glass, dp));
    }
};