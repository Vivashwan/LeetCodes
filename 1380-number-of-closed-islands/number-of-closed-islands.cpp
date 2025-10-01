class Solution {
private:
    vector<int>parent, rank;

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

        if(px==py)
        {
            return;
        }

        if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else if(rank[px]>rank[py])
        {
            parent[py]=px;
        }
        else
        {
            parent[py]=px;
            rank[px]++;
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        parent.resize(n*m+1);

        iota(parent.begin(), parent.end(), 0);

        rank.resize(n*m+1, 0);

        int VIRTUAL=n*m;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==0)
                {
                    int id=i*m+j;

                    if(i==0 || i==n-1 || j==0 || j==m-1)
                    {
                        unite(id, VIRTUAL);
                    }

                    if(i+1<n && grid[i+1][j]==0)
                    {
                        unite((i+1)*m+j, id);
                    }
                    
                    if(j-1>=0 && grid[i][j-1]==0)
                    {
                        unite(i*m+j-1, id);
                    }
                }
            }
        }

        unordered_set<int>comp;
        int virtualRoot=find(VIRTUAL);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==0)
                {
                    int id=i*m+j;

                    if(find(id)!=virtualRoot)
                    {
                        comp.insert(find(id));
                    }
                }
            }
        }

        return comp.size();
    }
};