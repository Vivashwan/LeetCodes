class Solution {
private:
    vector<int>parent, size;

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
        else if(size[px]>size[py])
        {
            parent[py]=px;
        }
        else if(size[px]<size[py])
        {
            parent[px]=py;
        }
        else
        {
            parent[py]=px;
            size[px]++;
        }
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();

        parent.resize(4*n*n);
        size.resize(4*n*n, 1);

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
                    unite(id+2, id+3);
                }
                else
                {
                    unite(id, id+1);
                    unite(id+1, id+2);
                    unite(id+2, id+3);
                    unite(id, id+3);
                }

                if(j+1<n)
                {
                    unite(4*(i*n+j)+1, 4*(i*n+j+1)+3);
                }

                if(i+1<n)
                {
                    unite(4*(i*n+j)+2, 4*((i+1)*n+j)+0);
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