class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(), m=mat[0].size();

        vector<vector<int>>grid(n+1, vector<int>(m+1, 0));

        int res=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                grid[i+1][j+1] = mat[i][j]+grid[i+1][j]+grid[i][j+1]-grid[i][j];
            }
        }

        for(int size=1; size<=min(n, m); size++)
        {
            for(int i=size; i<=n; i++)
            {
                for(int j=size; j<=m; j++)
                {
                    int total = grid[i][j]-grid[i-size][j]-grid[i][j-size]+grid[i-size][j-size];

                    if(total<=threshold)
                    {
                        res = max(res, size);
                    }
                }
            }
        }

        return res;
    }
};