class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> res(m, -1);

        for(int j = 0; j < m; j++) 
        {
            int col = j;

            for(int row = 0; row < n; row++) 
            {
                if(grid[row][col] == 1) 
                {
                    if(col + 1 < m && grid[row][col + 1] == 1) 
                    {
                        col++;
                    } else 
                    {
                        col = -1;
                        break;
                    }
                } 
                else if(grid[row][col] == -1) 
                {
                    if(col - 1 >= 0 && grid[row][col - 1] == -1) 
                    {
                        col--; 
                    } 
                    else 
                    {
                        col = -1; 
                        break;
                    }
                }
            }

            if(col != -1) 
            {
                res[j] = col; 
            }
        }

        return res;
    }
};
