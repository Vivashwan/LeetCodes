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

        if(rank[px]>rank[py])
        {
            parent[py]=px;
        }
        else if(rank[py]>rank[px])
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
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        parent.resize(4*n*n);
        rank.resize(4*n*n, 0);

        iota(parent.begin(), parent.end(), 0);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int id=4*(i*n+j);

                if(grid[i][j]=='/')
                {
                    unite(id, id+3);
                    unite(id+1, id+2);
                }
                else if(grid[i][j]=='\\')
                {
                    unite(id, id+1);
                    unite(id+3, id+2);
                }
                else
                {
                    unite(id, id+1);
                    unite(id+1, id+2);
                    unite(id+2, id+3);
                    unite(id+3, id);
                }

                if(i+1<n)
                {
                    unite(id+2, 4*((i+1)*n+j));
                }

                if(j+1<n)
                {
                    unite(id+1, 4*(i*n+j+1)+3);
                }
            }
        }

        int count=0;

        for(int i=0; i<4*n*n; i++)
        {
            if(find(i)==i)
            {
                count++;
            }
        }
        
        return count;
    }
};