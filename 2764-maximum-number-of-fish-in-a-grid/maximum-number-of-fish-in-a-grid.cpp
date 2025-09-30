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
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        parent.resize(n*m);

        for(int i=0; i<n*m; i++)
        {
            parent[i]=i;
        }

        for(int i=0; i<n; i++)
        {

            for(int j=0; j<m; j++)
            {
                if(grid[i][j]>0)
                {
                    int id=i*m+j;

                    if(i+1<n && grid[i+1][j]>0)
                    {
                        unite((i+1)*m+j, id);
                    }

                    if(j>0 && grid[i][j-1]>0)
                    {
                        unite(i*m+j-1, id);
                    }
                }
            }
        }

        unordered_map<int, int>mp;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]>0)
                {
                    int id=i*m+j;

                    mp[find(id)]+=grid[i][j];
                }
            }
        }

        int count=0;

        for(auto it: mp)
        {
            count=max(count, it.second);
        }

        return count;
    }
};