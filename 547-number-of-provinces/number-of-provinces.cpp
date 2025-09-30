class Solution {
private:
    vector<int>parent, rank; 

    int find(int x) 
    {
        if(parent[x]!=x) 
        {
            parent[x]=find(parent[x]);
        }

        return parent[x];
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n);
        rank.resize(n, 0);

        iota(parent.begin(), parent.end(), 0);

        for(int i=0; i<n; i++) 
        {
            for(int j=i+1; j<n; j++) 
            {
                if(isConnected[i][j]==1) 
                {
                    unite(i, j);
                }
            }
        }

        unordered_set<int>provinces;

        for(int i=0; i<n; i++) 
        {
            provinces.insert(find(i));
        }

        return provinces.size();
    }
};
