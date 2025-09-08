class Solution {
private:
    int maxi=0;

    void func(vector<vector<int>>&grid, int i, int j, int n, int m, int &count, vector<vector<bool>>&visited)
    {
        visited[i][j]=true;
        count++;

        maxi=max(maxi, count);

        int dirX[4]={-1, 0, 0, 1}, dirY[4]={0, 1, -1, 0};

        for(int k=0; k<4; k++)
        {
            int newX=i+dirX[k], newY=j+dirY[k];

            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1 && !visited[newX][newY])
            {
                func(grid, newX, newY, n, m, count, visited);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    int count=0;

                    func(grid, i, j, n, m, count, visited);
                }
            }
        }

        return maxi;
    }
};