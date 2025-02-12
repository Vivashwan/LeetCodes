class Solution {
private:
    int greedy(vector<vector<int>>& triangle, int n, int row, int col, vector<vector<int>>&dp) {
        if(row==n-1) 
        {
            return triangle[row][col];
        }

        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        
        int leftSum=greedy(triangle, n, row+1, col, dp), 
        rightSum=greedy(triangle, n, row+1, col+1, dp);
        
        return dp[row][col] = triangle[row][col]+min(leftSum, rightSum);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));

        return greedy(triangle, n, 0, 0, dp);
    }
};