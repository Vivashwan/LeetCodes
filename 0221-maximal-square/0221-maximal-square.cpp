class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        int maxSide=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]=='1') 
                {
                    if(i==0 || j==0) 
                    {
                        dp[i][j]=1;
                    } 
                    else 
                    {
                        dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                }

                maxSide = max(maxSide, dp[i][j]);
            }
        }

        return maxSide*maxSide;
    }
};