class Solution {
private:
    int maxim=0;
    void func(int row, int col, vector<vector<int>>&grid, int n, int m, int sum)
    {
        sum+=grid[row][col];

        int temp=grid[row][col];

        grid[row][col]=0;

        int rowNbr[4]={-1, 0, 0, 1}, colNbr[4]={0, -1, 1, 0};

        for(int i=0; i<4; i++)
        {
            int newRow=row+rowNbr[i], newCol=col+colNbr[i];

            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]!=0)
            {
                func(newRow, newCol, grid, n, m, sum);
            }
        }

        maxim=max(maxim, sum);
        grid[row][col]=temp;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]!=0)
                {
                    func(i, j, grid, n, m, 0);
                }
            }
        }

        return maxim;
    }
};