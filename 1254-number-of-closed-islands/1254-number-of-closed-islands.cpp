class Solution {
private:
    void func(int i, int j, vector<vector<int>>& grid)
    {
        int n=grid.size(), m=grid[0].size();
        grid[i][j]=1;

        int dirX[4]={-1, 0, 0, 1}, dirY[4]={0, 1, -1, 0};

        for(int k=0; k<4; k++)
        {
            int newX=dirX[k]+i, newY=dirY[k]+j;

            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==0)
            {
                func(newX, newY, grid);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==0)
            {
                func(i, 0, grid);
            }

            if(grid[i][m-1]==0)
            {
                func(i, m-1, grid);
            }
        }

        for(int j=1; j<m-1; j++)
        {
            if(grid[0][j]==0)
            {
                func(0, j, grid);
            }

            if(grid[n-1][j]==0)
            {
                func(n-1, j, grid);
            }
        }

        int count=0;

        for(int i=1; i<n-1; i++)
        {
            for(int j=1; j<m-1; j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    func(i, j, grid);
                }
            }
        }

        return count;
    }
};