class Solution {
public:
    int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    int OFFSET = 10;

    double dfs(int n, int k, int row, int col, vector<vector<vector<double>>>&dp) 
    {
        if(row<0 || col<0 || row>=n || col>=n) 
        {
            return 0.0; 
        }

        if(k==0)
        {
            return 1.0;
        }

        if(dp[row][col][k]!=-1.0)
        {
            return dp[row][col][k];
        }

        double res=0.0;

        for(auto &it: dir) 
        {
            res+=dfs(n, k-1, row+it[0], col+it[1], dp)/8.0;
        }

        return dp[row][col][k] = res;
    }

    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>>dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1.0)));
        
        return dfs(n, k, row, col, dp);
    }
};