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
        else if(rank[px]>rank[py])
        {
            parent[py]=px;
        }
        else if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else
        {
            parent[py]=px;
            rank[px]++;
        }
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();

        parent.resize(n*m);
        rank.resize(n*m, 0);

        iota(parent.begin(), parent.end(), 0);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int id=i*m+j;

                if(i+1<n && grid[i+1][j]==grid[i][j])
                {
                    if(find(id)==find((i+1)*m+j))
                    {
                        return true;
                    }

                    unite(id, (i+1)*m+j);
                }

                if(j-1>=0 && grid[i][j-1]==grid[i][j])
                {
                    if(find(id)==find(i*m+j-1))
                    {
                        return true;
                    }

                    unite(id, i*m+j-1);
                }
            }
        }

        return false;
    }   
};