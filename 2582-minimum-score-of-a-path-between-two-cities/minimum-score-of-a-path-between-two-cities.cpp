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
        else if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else if(rank[py]<rank[px])
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
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n);
        rank.resize(n, 0);

        iota(parent.begin(), parent.end(), 0);

        unordered_map<int, int> minWeight;

        for(auto &road: roads) 
        {
            int u=road[0]-1, v=road[1]-1, w=road[2];
            unite(u, v);
        }

        for(auto &road: roads) 
        {
            int u=find(road[0]-1), v=find(road[1]-1), w=road[2];

            int root=find(u);

            if(!minWeight.count(root)) 
            {
                minWeight[root]=w;
            }
            else minWeight[root]=min(minWeight[root], w);
        }

        int root1=find(0), rootN=find(n-1);

        if(root1==rootN)
        { 
            return minWeight[root1];
        }
        else return -1;
    }
};