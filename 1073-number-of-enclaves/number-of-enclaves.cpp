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
    int numEnclaves(vector<vector<int>>& grid) {
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
                if(grid[i][j]==1)
                {
                    int id=i*m+j;

                    if(i>0 && grid[i-1][j]==1)
                    {
                        unite(id, (i-1)*m+j);
                    }

                    if(j>0 && grid[i][j-1]==1)
                    {
                        unite(id, i*m+j-1);
                    }
                }
            }
        }

        unordered_set<int>borderParents;

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)) 
                {
                    int id=i*m+j;
                    int p=find(id);
                    borderParents.insert(p);
                }
            }
        }

        int count=0;

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                if(grid[i][j]==1) 
                {
                    int id=i*m+j;
                    int p=find(id);

                    if(borderParents.find(p)==borderParents.end())
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};