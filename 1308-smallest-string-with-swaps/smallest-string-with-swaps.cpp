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
        else if(rank[py]>rank[px])
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();

        parent.resize(n);
        rank.resize(n, 0);

        iota(parent.begin(), parent.end(), 0);

        for(auto it: pairs)
        {
            unite(it[0], it[1]);
        }

        unordered_map<int, vector<int>>compInd;
        unordered_map<int, vector<char>>compVals;

        for(int i=0; i<n; i++)
        {
            int root=find(i);

            compInd[root].push_back(i);

            compVals[root].push_back(s[i]);
        }

        for(auto it: compInd)
        {
            auto indices=it.second;

            sort(indices.begin(), indices.end());

            auto values=compVals[it.first];

            sort(values.begin(), values.end());

            for(int i=0; i<indices.size(); i++)
            {
                s[indices[i]]=values[i];
            }
        }

        return s;
    }
};