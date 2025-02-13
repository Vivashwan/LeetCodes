class Solution {
    void func(vector<vector<int>>& matrix, int n, vector<vector<int>>&dp)
    {
        for(int j=0; j<n; j++)
        {
            dp[n-1][j]=matrix[n-1][j];
        }

        for(int row=n-2; row>=0; row--)
        {
           for(int col=n-1; col>=0; col--)
           {
                int left = (col>0) ? matrix[row][col] + dp[row+1][col-1] : INT_MAX;
                int below = matrix[row][col] + dp[row+1][col];
                int right = (col<n-1) ? matrix[row][col] + dp[row+1][col+1] : INT_MAX;

                dp[row][col] = min(left, min(below, right));
            }
        }

        return;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int mini = INT_MAX;

        vector<vector<int>>dp(n+1, vector<int>(n+1, INT_MAX));

        func(matrix, n, dp);

        for (int i = 0; i < n; i++)
        {
            mini = min(mini, dp[0][i]);
        }

        return mini;
    }
};