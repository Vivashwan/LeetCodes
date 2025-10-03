class Solution {
private:
    vector<int>parent, rankv;

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

        if(rankv[px]>rankv[py]) 
        {
            parent[py] = px;
        } 
        else if(rankv[px]<rankv[py]) 
        {
            parent[px]=py;
        } 
        else 
        {
            parent[py]=px;
            rankv[px]++;
        }
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();

        parent.resize(n*m);
        rankv.resize(n*m, 0);

        iota(parent.begin(), parent.end(), 0);

        vector<tuple<int, int, int>>edges;

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                int id=i*m+j;

                if(i+1<n) 
                {
                    int nid=(i+1)*m+j;
                    int diff=abs(heights[i][j] - heights[i+1][j]);
                    edges.push_back({diff, id, nid});
                }

                if(j+1<m) 
                {
                    int nid=i*m+(j+1);
                    int diff=abs(heights[i][j] - heights[i][j+1]);
                    edges.push_back({diff, id, nid});
                }
            }
        }

        sort(edges.begin(), edges.end());

        int start=0, end=n*m-1;

        for(auto &it: edges) 
        {
            int effort=get<0>(it), u=get<1>(it), v=get<2>(it);

            unite(u, v);

            if(find(start)==find(end)) 
            {
                return effort;
            }
        }

        return 0;
    }
};
