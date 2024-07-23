class Solution {
private:
    int mod = 1e9+7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<long long>>maxProd(n, vector<long long>(m, 0));
        vector<vector<long long>>minProd(n, vector<long long>(m, 0));

        maxProd[0][0] = minProd[0][0] = grid[0][0];

        for(int i=1; i<n; i++)
        {
            maxProd[i][0] = minProd[i][0] = maxProd[i-1][0]*grid[i][0];
        }

        for(int j=1; j<m; j++)
        {
            maxProd[0][j] = minProd[0][j] = maxProd[0][j-1]*grid[0][j];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(grid[i][j]>=0)
                {
                    maxProd[i][j] = max(maxProd[i-1][j], maxProd[i][j-1])*grid[i][j];
                    minProd[i][j] = min(minProd[i-1][j], minProd[i][j-1])*grid[i][j];
                }
                else
                {
                    maxProd[i][j] = min(minProd[i-1][j], minProd[i][j-1])*grid[i][j];
                    minProd[i][j] = max(maxProd[i-1][j], maxProd[i][j-1])*grid[i][j];
                }
            }
        }

        long long result = maxProd[n-1][m-1];

        return result<0 ? -1 : result%mod;
    }
};