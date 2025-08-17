class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(), m=mat[0].size();

        vector<vector<int>>prefix(n+1, vector<int>(m+1, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                prefix[i+1][j+1]=prefix[i+1][j]+prefix[i][j+1]-prefix[i][j]+mat[i][j];
            }
        }

        int res=0;

        for(int size=1; size<=min(n, m); size++)
        {
            for(int i=size; i<=n; i++)
            {
                for(int j=size; j<=m; j++)
                {
                    int total=prefix[i][j]-prefix[i-size][j]-prefix[i][j-size]+prefix[i-size][j-size];

                    if(total<=threshold)
                    {
                        res=max(res, size);
                    }
                }
            }
        }

        return res;
    }
};