class Solution {
private:
    vector<int>parent, rank;

    const int OFFSET=10001, SIZE=20005;

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

        if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else if(rank[px]>rank[py])
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        parent.resize(SIZE);
        rank.resize(SIZE, 0);

        iota(parent.begin(), parent.end(), 0);

        for(auto it: stones)
        {
            unite(it[0], it[1]+OFFSET);
        }

        unordered_set<int>uniqueRoots;

        for(auto it: stones)
        {
            int row=it[0];
            uniqueRoots.insert(find(row));
        }

        int numComponents=uniqueRoots.size(), totalStones=stones.size();

        return totalStones-numComponents;
    }
};