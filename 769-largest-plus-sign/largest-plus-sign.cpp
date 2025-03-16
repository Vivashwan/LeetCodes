class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>grid(n, vector<int>(n, n));

        for(auto mine: mines)
        {    
            grid[mine[0]][mine[1]] = 0;
        }

        for(int i=0; i<n; i++) 
        {
            int left=0, right=0, up=0, down=0;
            
            for(int j=0; j<n; j++) 
            {
                left = (grid[i][j]==0) ? 0 : left+1;
                right = (grid[i][n-j-1]==0) ? 0 : right+1;
                grid[i][j] = min(grid[i][j], left); 
                grid[i][n-j-1] = min(grid[i][n-j-1], right);
            }

            for(int j=0; j<n; j++) 
            {
                up = (grid[j][i]==0) ? 0 : up+1;
                down = (grid[n-j-1][i]==0) ? 0 : down+1;
                grid[j][i] = min(grid[j][i], up);
                grid[n-j-1][i] = min(grid[n-j-1][i], down);
            }
        }

        int maxOrder=0;

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                maxOrder = max(maxOrder, grid[i][j]);
            }
        }

        return maxOrder;
    }
};