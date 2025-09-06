class Solution {
public:
    void dfs(vector<vector<int>>&grid, int i, int j, int n) 
    {
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==1)
        {    
            return;
        }
        
        grid[i][j]=1;
        
        dfs(grid, i+1, j, n);
        dfs(grid, i-1, j, n);
        dfs(grid, i, j+1, n);
        dfs(grid, i, j-1, n);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int expandedN=n*3;
        
        vector<vector<int>>expandedGrid(expandedN, vector<int>(expandedN, 0));
        
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                char c=grid[i][j];
                int r=i*3, c3=j*3;
                
                if(c=='/') 
                {
                    expandedGrid[r][c3+2]=1;
                    expandedGrid[r+1][c3+1]=1;
                    expandedGrid[r+2][c3+0]=1;
                } 
                else if (c=='\\') 
                {
                    expandedGrid[r][c3+0]=1;
                    expandedGrid[r+1][c3+1]=1;
                    expandedGrid[r+2][c3+2]=1;
                }
            }
        }
        
        int regions=0;

        for(int i=0; i<expandedN; i++) 
        {
            for(int j=0; j<expandedN; j++) 
            {
                if(expandedGrid[i][j]==0) 
                {
                    dfs(expandedGrid, i, j, expandedN);
                    regions++;
                }
            }
        }
        
        return regions;
    }
};
