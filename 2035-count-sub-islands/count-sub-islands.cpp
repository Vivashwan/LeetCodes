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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(), m=grid1[0].size();

        parent.resize(n*m);

        for(int i=0; i<n*m; i++)
        {
            parent[i]=i;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid2[i][j]==1)
                {
                    int id=i*m+j;

                    if(i>0 && grid2[i-1][j])
                    {
                        unite((i-1)*m+j, id);
                    }

                    if(j>0 && grid2[i][j-1])
                    {
                        unite(i*m+j-1, id);
                    }
                }
            }
        }

        unordered_map<int, bool>valid;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid2[i][j]==1)
                {
                    int root=find(i*m+j);
                    valid[root]=true;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid2[i][j]==1 && grid1[i][j]==0)
                {
                    int root=find(i*m+j);
                    valid[root]=false;
                }
            }
        }

        int count=0;

        for(auto &it: valid)
        {
            if(it.second)
            { 
                count++;
            }
        }

        return count;
    }
};