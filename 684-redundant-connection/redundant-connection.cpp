class Solution {
private:
    bool func(int u, int v, unordered_map<int, vector<int>>&adj, vector<bool>&visited)
    {
        if(u==v)
        {
            return true;
        }

        visited[u]=true;

        for(auto it: adj[u])
        {
            if(!visited[it])
            {
                if(func(it, v, adj, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;

        for(auto edge: edges)
        {
            int u=edge[0], v=edge[1];

            if(!adj[u].empty() && !adj[v].empty())
            {
                vector<bool>visited(1001, false);

                if(func(u, v, adj, visited))
                {
                    return edge;
                }
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};