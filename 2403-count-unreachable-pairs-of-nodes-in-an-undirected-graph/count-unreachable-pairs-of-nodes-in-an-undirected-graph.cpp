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
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);

        iota(parent.begin(), parent.end(), 0);

        for(auto it: edges)
        {
            unite(it[0], it[1]);
        }

        unordered_map<int, int>compSize;

        for(int i=0; i<n; i++)
        {
            compSize[find(i)]++;
        }

        long long count=0, remaining=n;

        for(auto it: compSize)
        {
            long long size=it.second;

            count+=size*(remaining-size);
            remaining-=size;
        }

        return count;
    }
};