class Solution {
public:
    int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    int OFFSET = 10;

    double dfs(int n, int k, int row, int col, vector<vector<vector<double>>>&dp) 
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dp[i][j][0]=1.0;
            }
        }

        for(int steps=1; steps<=k; steps++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    double res=0.0;

                    for(auto &it: dir) 
                    {
                        if(i+it[0]>=0 && j+it[1]>=0 && i+it[0]<n && j+it[1]<n) 
                        {
                            res+=(dp[i+it[0]][j+it[1]][steps-1])/8.0; 
                        }
                    }

                    dp[i][j][steps] = res;
                }
            }
        }

        return dp[row][col][k];
    }

    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>>dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1, 0)));
        
        return dfs(n, k, row, col, dp);
    }
};