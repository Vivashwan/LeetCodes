class Solution {
private:
    int func(vector<vector<char>>& matrix, int n, int m, int row, int col, vector<vector<int>>&dp)
    {
        if(row<0 || col<0)
        {
            return 0;
        }

        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }

        if(matrix[row][col]=='0')
        {
            return 0;
        }

        return dp[row][col] = 1+min({func(matrix, n, m, row-1, col, dp), func(matrix, n, m, row, col-1, dp), func(matrix, n, m, row-1, col-1, dp)});
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        int maxSide=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                maxSide=max(maxSide, func(matrix, n, m, i, j, dp));
            }
        }

        return maxSide*maxSide;
    }
};