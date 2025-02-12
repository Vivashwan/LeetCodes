class Solution {
private:
    int greedy(vector<vector<int>>& triangle, int n, vector<vector<int>>&dp) 
    {
        for(int j=0; j<n; j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int row=n-1; row>=0; row--)
        {
            for(int col=0; col<=row; col++)
            {
                int leftSum=dp[row+1][col], rightSum=dp[row+1][col+1];
                
                dp[row][col] = triangle[row][col]+min(leftSum, rightSum);
            }
        }

        return dp[0][0];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        return greedy(triangle, n, dp);
    }
};