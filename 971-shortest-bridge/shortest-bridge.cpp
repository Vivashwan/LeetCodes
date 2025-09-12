class Solution {
private:
    int dirX[4]={-1, 0, 0, 1}, dirY[4]={0, 1, -1, 0};

    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m, queue<pair<int, int>>&q)
    {
        grid[i][j]=2;

        q.push({i, j});

        for(int k=0; k<4; k++)
        {
            int newX=i+dirX[k], newY=j+dirY[k];

            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1)
            {
                dfs(newX, newY, grid, n, m, q);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        queue<pair<int, int>>q;

        for(int i=0; i<n; i++)
        {
            bool isFound=false;
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i, j, grid, n, m, q);
                    isFound=true;
                    break;
                }

            }
            
            if(isFound==true)
            {
                break;
            }
        }

        int count=0;

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0; i<size; i++)
            {
                auto it=q.front();
                q.pop();

                int x=it.first, y=it.second;

                for(int k=0; k<4; k++)
                {
                    int newX=x+dirX[k], newY=y+dirY[k];

                    if(newX>=0 && newX<n && newY>=0 && newY<m)
                    {
                        if(grid[newX][newY]==1)
                        {
                            return count;
                        }

                        if(grid[newX][newY]==0)
                        {
                            grid[newX][newY]=2;
                            q.push({newX, newY});
                        }

                    }
                }
            }

            count++;
        }

        return count;
    }
};