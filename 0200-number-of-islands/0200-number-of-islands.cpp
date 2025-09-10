class Solution {
private:
    void dfs(int i, int j, int n, int m, vector<vector<char>>&grid)
    {
        grid[i][j]='0';

        int dirX[4]={-1, 0, 0, 1}, dirY[4]={0, -1, 1, 0};

        for(int k=0; k<4; k++)
        {
            int newX=i+dirX[k], newY=j+dirY[k];

            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]=='1')
            {
                dfs(newX, newY, n, m, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();

        int count=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;

                    dfs(i, j, n, m, grid);
                }
            }
        }

        return count;
    }
};