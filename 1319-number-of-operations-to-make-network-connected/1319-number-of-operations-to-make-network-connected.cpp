class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // Not enough cables to connect all nodes
        
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        
        for (const auto& connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        
        int connected_components = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(graph, visited, i);
                ++connected_components;
            }
        }
        
        return connected_components - 1; // Minimum number of cables needed
    }
    
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }
};