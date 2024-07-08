class Solution {
private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m, char ch, int parentX, int parentY, int fromX, int fromY) 
    {
        visited[parentX][parentY] = true;

        int xPos[4] = {0, -1, 1, 0};
        int yPos[4] = {-1, 0, 0, 1};

        for(int i = 0; i < 4; i++) 
        {
            int newPosX = parentX + xPos[i];
            int newPosY = parentY + yPos[i];

            if(newPosX >= 0 && newPosX < n && newPosY >= 0 && newPosY < m) 
            {
                if(grid[newPosX][newPosY] == ch) 
                {
                    if(!visited[newPosX][newPosY]) 
                    {
                        if(dfs(grid, visited, n, m, ch, newPosX, newPosY, parentX, parentY))
                        {
                            return true;
                        }
                    } 
                    else if(newPosX != fromX || newPosY != fromY) 
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                if(!visited[i][j]) 
                {
                    if(dfs(grid, visited, n, m, grid[i][j], i, j, -1, -1)) 
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
