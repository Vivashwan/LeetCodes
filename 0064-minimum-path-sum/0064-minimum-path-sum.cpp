class Solution {
private:
    bool isSafe(int n, int m, int newRow, int newCol) {
        return (newRow < n && newCol < m);
    }

    int func(vector<vector<int>>& grid, int n, int m, int row, int col, vector<vector<int>>& dp) {
        if (row == n - 1 && col == m - 1) {
            return grid[row][col];  // Correct base case
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int rowNbr[2] = {0, 1}, colNbr[2] = {1, 0};
        int mini = INT_MAX;

        for (int i = 0; i < 2; i++) {
            int newRow = row + rowNbr[i], newCol = col + colNbr[i];

            if (isSafe(n, m, newRow, newCol)) {
                mini = min(mini, grid[row][col] + func(grid, n, m, newRow, newCol, dp));
            }
        }

        return dp[row][col] = mini;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));  // Correct size
        return func(grid, n, m, 0, 0, dp);
    }
};
