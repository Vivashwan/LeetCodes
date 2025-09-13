class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        queue<pair<int, int>>q;

        int freshOranges=0, minutes=0;

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                if(grid[i][j]==2) 
                {
                    q.push({i, j});
                } 
                else if(grid[i][j]==1) 
                {
                    freshOranges++;
                }
            }
        }

        int dx[4] = {-1, 0, 0, 1}, dy[4]={0, -1, 1, 0};

        while(!q.empty() && freshOranges>0) 
        {
            int size=q.size();
            minutes++;

            for(int i=0; i<size; i++) 
            {
                auto [x, y]=q.front();
                q.pop();

                for(int d=0; d<4; d++) 
                {
                    int newX=x+dx[d], newY=y+dy[d];

                    if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1) 
                    {
                        grid[newX][newY]=2;

                        freshOranges--;

                        q.push({newX, newY});
                    }
                }
            }
        }

        return freshOranges==0 ? minutes : -1;
    }
};
