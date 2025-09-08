class Solution {
public:
    vector<int>dirX={0, 0, 1, -1}, dirY={1, -1, 0, 0};
    
    void dfs(int x, int y, vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        
        grid[x][y]=0;
        
        for(int d=0; d<4; d++) 
        {
            int nx=x+dirX[d], ny=y+dirY[d];
            
            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1) 
            {
                dfs(nx, ny, grid);
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(), n=grid1[0].size();
        
        for(int i=0; i<m; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                if(grid2[i][j]==1 && grid1[i][j]==0) 
                {
                    dfs(i, j, grid2);
                }
            }
        }
        
        int subIslands=0;

        for(int i=0; i<m; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                if(grid2[i][j]==1) 
                {
                    subIslands++;
                    dfs(i, j, grid2);
                }
            }
        }
        
        return subIslands;
    }
};