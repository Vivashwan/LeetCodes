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

        if(size[px]<size[py])
        { 
            swap(px, py);
        }

        parent[py]=px;
        size[px]+=size[py];
    }

public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool>isRestricted(n, false);

        parent.resize(n);
        size.resize(n, 1);

        iota(parent.begin(), parent.end(), 0);

        for(int r: restricted)
        {
            isRestricted[r]=true;
        }

        if(isRestricted[0])
        { 
            return 0;
        }

        for(auto &e: edges) 
        {
            int u=e[0], v=e[1];

            if(!isRestricted[u] && !isRestricted[v]) 
            {
                unite(u, v);
            }
        }

        return size[find(0)];
    }
};
