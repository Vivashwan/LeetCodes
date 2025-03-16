class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>row(n, vector<int>(m, 0)), col(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                if(grid[i][j]==1) 
                {
                    row[i][j] = (j==0) ? 1 : row[i][j-1]+1;
                    col[i][j] = (i==0) ? 1 : col[i-1][j]+1;
                }
            }
        }
        
        int maxSquare=0;
        
        for(int i=n-1; i>=0; i--) 
        {
            for(int j=m-1; j>=0; j--) 
            {
                int size = min(row[i][j], col[i][j]);

                while(size>maxSquare) 
                { 
                    if(row[i-size+1][j]>=size && col[i][j-size+1]>=size) 
                    {
                        maxSquare=size;
                    }
                    size--;
                }
            }
        }
        
        return maxSquare*maxSquare;
    }
};