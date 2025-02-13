class Solution {
private:
    double func(int poured, int row, int col, vector<vector<double>>&dp)
    {
        if(row<0 || col<0 || col>row)
        {
            return 0.0;
        }

        if(row==0 && col==0)
        {
            return poured;
        }

        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }

        double left = max(0.0, (func(poured, row - 1, col - 1, dp) - 1) / 2.0);
        double right = max(0.0, (func(poured, row - 1, col, dp) - 1) / 2.0);

        return dp[row][col] = left+right;
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(query_row+1, vector<double>(query_glass+1, -1));
        return min(1.0, func(poured, query_row, query_glass, dp));
    }
};