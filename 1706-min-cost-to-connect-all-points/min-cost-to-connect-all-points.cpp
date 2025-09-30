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

    bool unite(int x, int y)
    {
        int px=find(x), py=find(y);

        if(px==py)
        {
            return false;
        }

        if(rank[px]<rank[py])
        {
            swap(px, py);
        }

        parent[py]=px;

        if(rank[px]==rank[py])
        {
            rank[px]++;
        }

        return true;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        parent.resize(n);
        rank.resize(n, 0);

        for(int i=0; i<n; i++)
        {
            parent[i]=i;
        }

        vector<tuple<int, int, int>>edges;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);

                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int cost=0, edgesUsed=0;

        for(auto [w, u, v]: edges)
        {
            if(unite(u, v))
            {
                cost+=w;
                edgesUsed++;

                if(edgesUsed==n-1)
                {
                    break;
                }
            }
        }

        return cost;
    }
};