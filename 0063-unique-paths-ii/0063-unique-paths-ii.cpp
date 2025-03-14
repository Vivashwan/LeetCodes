class Solution {
private:
    bool isSafe(vector<vector<int>>& obstacleGrid, int n, int m, int newRow, int newCol)
    {
        if(newRow >=n || newCol>=m || obstacleGrid[newRow][newCol]==1)
        {
            return false;
        }

        return true;
    }

    int func(vector<vector<int>>& obstacleGrid, int n, int m, int row, int col, vector<vector<int>>&dp)
    {
        if(row==n-1 && col==m-1)
        {
            return 1;
        }

        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }

        int rowNbr[2]={0, 1}, colNbr[2]={1, 0};

        int count=0;

        for(int i=0; i<2; i++)
        {
            int newRow=row+rowNbr[i], newCol=col+colNbr[i];

            if(isSafe(obstacleGrid, n, m, newRow, newCol))
            {
                count+=func(obstacleGrid, n, m, newRow, newCol, dp);
            }
        }

        return dp[row][col] = count;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

        return func(obstacleGrid, n, m, 0, 0, dp);
    }
};