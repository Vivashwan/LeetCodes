class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        {
            return -1;
        }

        queue<pair<int, int>>q;

        grid[0][0]=1;
        q.push({0, 0});

        int count=0;

        while(!q.empty())
        {
            int size=q.size();
            count++;

            for(int i=0; i<size; i++)
            {
                auto [x, y]=q.front(); q.pop();

                if(x==n-1 && y==n-1)
                {
                    return count;
                }

                int dx[8]={1,-1,0,0,1,1,-1,-1};
                int dy[8]={0,0,1,-1,1,-1,1,-1};

                for(int j=0; j<8; j++)
                {
                    int newX=x+dx[j], newY=y+dy[j];

                    if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==0)

                    {
                        grid[newX][newY]=1;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return -1;
    }
};