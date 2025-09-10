class Solution {
private:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited) 
    {
        visited[node]=true;

        for(int neighbor: adj[node]) 
        {
            if(!visited[neighbor]) 
            {
                dfs(neighbor, adj, visited);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {    
            return -1;
        }

        vector<vector<int>>adj(n);

        for(auto& conn: connections) 
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<bool>visited(n, false);
        int components=0;

        for(int i=0; i<n; i++) 
        {
            if(!visited[i]) 
            {
                components++;
                dfs(i, adj, visited);
            }
        }

        return components-1;
    }
};
