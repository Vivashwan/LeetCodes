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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables=connections.size();

        if(cables<n-1)
        {
            return -1;
        }

        parent.resize(n+1);
        rank.resize(n+1, 0);

        iota(parent.begin(), parent.end(), 0);

        for(auto &it: connections) 
        {
            unite(it[0], it[1]);
        }

        int components=0;

        for(int i=0; i<n; i++) 
        {
            if(find(i)==i)
            { 
                components++;
            }
        }

        return components-1;
    }
};