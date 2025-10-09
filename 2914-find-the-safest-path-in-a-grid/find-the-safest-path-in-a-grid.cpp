class Solution {
private:
    vector<int>parent, size;

    int find(int x) 
    {
        return parent[x]==x ? x:parent[x]=find(parent[x]);
    }

    void unite(int x, int y) 
    {
        int px=find(x), py=find(y);
        if(px==py)
        { 
            return;
        }

        if(size[px]<size[py])
        { 
            swap(px, py);
        }

        parent[py]=px;
        size[px]+=size[py];
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n, vector<int>(n, -1));
        queue<pair<int,int>>q;

        parent.resize(n*n);
        size.assign(n*n, 1);

        iota(parent.begin(), parent.end(), 0);

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                if(grid[i][j]==1) 
                {
                    dist[i][j]=0;
                    q.push({i,j});
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

        struct Cell 
        {
            int safe, x, y;
        };

        vector<Cell>cells;

        cells.reserve(n*n);

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                cells.push_back({dist[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end(), [](const Cell& a, const Cell& b) 
        {
            return a.safe>b.safe;
        });

        vector<vector<bool>>active(n, vector<bool>(n, false));

        auto idx=[&](int x, int y) 
        {
            return x*n+y;
        };

        for(auto &cell: cells) 
        {
            int x=cell.x, y=cell.y;

            active[x][y]=true;

            for(int d=0; d<4; d++) 
            {
                int nx=x+dirs[d], ny=y+dirs[d+1];

                if(nx>=0 && nx<n && ny>=0 && ny<n && active[nx][ny]) 
                {
                    unite(idx(x,y), idx(nx,ny));
                }
            }

            if(find(0)==find(n*n-1)) 
            {
                return cell.safe;
            }
        }

        return 0;
    }
};