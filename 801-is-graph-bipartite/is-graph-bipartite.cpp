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
            swap(px, py);
        }

        parent[py]=px;

        if(rank[px]==rank[py])
        { 
            rank[px]++;
        }
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);

        for(int u=0; u<n; u++) 
        {
            if(graph[u].empty())
            { 
                continue;
            }

            int firstNeighbor=graph[u][0];

            for(int v: graph[u]) 
            {
                if(find(u)==find(v))
                {    
                    return false;
                }

                unite(firstNeighbor, v);
            }
        }

        return true;
    }
};
