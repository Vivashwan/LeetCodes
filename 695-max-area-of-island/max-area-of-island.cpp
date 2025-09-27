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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        parent.resize(n*m);

        for(int i=0;i<n*m;i++)
        { 
            parent[i]=i;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int id=i*m+j;

                    if(j>0 && grid[i][j-1]==1)
                    { 
                        unite(id, i*m+(j-1));
                    }

                    if(i>0 && grid[i-1][j]==1)
                    { 
                        unite(id, (i-1)*m+j);
                    }
                }
            }
        }

        unordered_map<int,int>compSize;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int id=i*m+j;
                    compSize[find(id)]++;
                }
            }
        }

        int maxArea=0;
        for(auto it: compSize)
        { 
            maxArea=max(maxArea, it.second);
        }

        return maxArea;
    }

};