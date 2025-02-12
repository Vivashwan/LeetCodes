class Solution {
private:
    int MOD = 1e9+7;
    int func(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>&dp)
    {
        if(startRow>=m || startColumn>=n || startRow<0 || startColumn<0)
        {
            return 1;
        }

        if(maxMove==0)
        {
            return 0;
        }

        if(dp[maxMove][startRow][startColumn]!=-1)
        {
            return dp[maxMove][startRow][startColumn];
        }
           
        int row_nbr[4] = {-1, 0, 0, 1}, col_nbr[4] = {0, -1, 1, 0};

        long long res=0;

        for(int i=0; i<4; i++)
        {
            int newRow=startRow+row_nbr[i];
            int newCol=startColumn+col_nbr[i];

            res=(res+func(m, n, maxMove-1, newRow, newCol, dp))%MOD;
        }

        return dp[maxMove][startRow][startColumn] = res;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(maxMove+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return func(m, n, maxMove, startRow, startColumn, dp);
    }
};