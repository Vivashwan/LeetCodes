class Solution {
private:
    vector<int>parent;
    
    int find(int x) 
    {
        while(parent[x]!=x)
        { 
            parent[x]=parent[parent[x]];
            x=parent[x];
        }

        return x;
    }

    void unite(int x, int y) 
    {
        int px=find(x), py=find(y);

        if(px!=py)
        { 
            parent[px]=py;
        }
    }

    bool connected(int x, int y) 
    {
        return find(x) == find(y);
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        parent.resize(n*m);

        iota(parent.begin(), parent.end(), 0);

        unordered_map<int, vector<pair<int,int>>>dir={
            {1, {{0,-1},{0,1}}},
            {2, {{-1,0},{1,0}}},
            {3, {{0,-1},{1,0}}},
            {4, {{0,1},{1,0}}},
            {5, {{0,-1},{-1,0}}},
            {6, {{0,1},{-1,0}}}
        };

        auto inBounds = [&](int x,int y){ return x>=0 && x<n && y>=0 && y<m; };

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                int curType=grid[i][j];

                for(auto &[dx, dy]: dir[curType]) 
                {
                    int ni=i+dx, nj=j+dy;

                    if(!inBounds(ni,nj)) 
                    {
                        continue;
                    }

                    int neighType=grid[ni][nj];

                    for(auto &[ndx, ndy]: dir[neighType]) 
                    {
                        if(ni+ndx==i && nj+ndy==j) 
                        {
                            unite(i*m+j, ni*m+nj);
                            break;
                        }
                    }
                }
            }
        }

        return connected(0, n*m-1);
    }
};