class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        queue<pair<int,int>>q;

        vector<vector<int>>visited(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                if(grid[i][j]==1) 
                {
                    q.push({i, j});
                    visited[i][j]=1;
                    break;
                }
            }

            if(!q.empty())
            { 
                break;
            }
        }

        int res=0;
        vector<int> dirX={-1, 0, 0, 1};
        vector<int> dirY={0, -1, 1, 0};

        while(!q.empty()) 
        {
            auto [x, y]=q.front(); q.pop();

            int count=4;

            for(int d=0; d<4; d++) 
            {
                int newX=x+dirX[d], newY=y+dirY[d];

                if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1) 
                {
                    count--;

                    if(!visited[newX][newY]) 
                    {
                        visited[newX][newY]=1;
                        q.push({newX, newY});
                    }
                }
            }
            
            res+=count;
        }

        return res;
    }
};
