class Solution {
private:
    bool isLand;
    
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m) {
        if(grid1[i][j] == 0) 
        {
            isLand = false;
        }

        grid2[i][j] = 0;

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(auto dir:directions) 
        {
            int x = i + dir[0], y = j + dir[1];

            if(x>=0 && x<n && y>=0 && y<m && grid2[x][y]==1) 
            {
                dfs(x, y, grid1, grid2, n, m);
            }
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int n = grid2.size(), m = grid2[0].size();

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                if(grid2[i][j]==1) 
                {
                    isLand = true;
                    dfs(i, j, grid1, grid2, n, m);
                    
                    if(isLand) 
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
