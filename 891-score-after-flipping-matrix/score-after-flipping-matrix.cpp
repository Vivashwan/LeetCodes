class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0; j<m; j++)
                {
                    grid[i][j]^=1;
                }
            }
        }

        int res=0;

        for(int j=0; j<m; j++)
        {
            int countOnes=0;

            for(int i=0; i<n; i++)
            {
                countOnes+=grid[i][j];
            }

            countOnes=max(countOnes, n-countOnes);

            res+=countOnes*(1<<(m-1-j));
        }

        return res;
    }
};