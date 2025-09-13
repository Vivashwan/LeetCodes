
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int, int>>q;
        
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                if(grid[i][j]==1) 
                {
                    q.push({i, j});
                }
            }
        }
        
        if(q.empty() || q.size()==n*n)
        { 
            return -1;
        }
        
        int maxDist=-1;

        vector<int>dirs={0, 1, 0, -1, 0};
        
        while(!q.empty()) 
        {
            int size=q.size();
            maxDist++;
            
            for(int i=0; i<size; i++) 
            {
                auto [x, y]=q.front();
                q.pop();
                
                for(int d=0; d<4; d++) 
                {
                    int nx=x+dirs[d], ny=y+dirs[d+1];
                    
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0) 
                    {
                        grid[nx][ny]=1;

                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return maxDist;
    }
};
