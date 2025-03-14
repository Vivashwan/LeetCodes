class Solution {
private:
    bool isSafe(int m, int n, int newRow, int newCol)
    {
        if(newRow >=m || newCol>=n)
        {
            return false;
        }

        return true;
    }

    int func(int m, int n, int row, int col, vector<vector<int>>&dp)
    {
        if(row==m-1 && col==n-1)
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

            if(isSafe(m, n, newRow, newCol))
            {
                count+=func(m, n, newRow, newCol, dp);
            }
        }

        return dp[row][col] = count;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return func(m, n, 0, 0, dp);
    }
};