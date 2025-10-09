class Solution {
private:
    bool canReach(vector<vector<int>>&dist, int val) 
    {
        int n=dist.size();

        if(dist[0][0]<val || dist[n-1][n-1]<val)
        { 
            return false;
        }

        queue<pair<int,int>>q;
        
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        q.push({0, 0});

        visited[0][0]=true;

        vector<int>dirs={0,1,0,-1,0};

        while(!q.empty()) 
        {
            auto [x, y]=q.front();
            q.pop();

            if(x==n-1 && y==n-1)
            { 
                return true;
            }

            for(int d=0; d<4; d++) 
            {
                int nx=x+dirs[d], ny=y+dirs[d+1];

                if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny] && dist[nx][ny]>=val) 
                    {
                    visited[nx][ny]=true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>>dist(n, vector<int>(n, -1));
        queue<pair<int,int>>q;

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                if(grid[i][j]==1) 
                {
                    dist[i][j]=0;
                    q.push({i, j});
                }
            }
        }

        vector<int>dirs={0,1,0,-1,0};

        while(!q.empty()) 
        {
            auto [x, y]=q.front();
            q.pop();

            for(int d=0; d<4; d++) 
            {
                int nx=x+dirs[d], ny=y+dirs[d+1];

                if(nx>=0 && nx<n && ny>=0 && ny<n && dist[nx][ny]==-1) 
                {
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }

        int left=0, right=2*n, ans=0;

        while(left<=right) 
        {
            int mid=(left+right)/2;

            if(canReach(dist, mid)) 
            {
                ans=mid;
                left=mid+1;
            } 
            else 
            {
                right=mid-1;
            }
        }

        return ans;
    }
};
