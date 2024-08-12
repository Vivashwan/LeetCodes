class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, int& goodNodesCount) {
        int size = 1;
        unordered_map<int, int> childSizes; 
        
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            
            int childSubtreeSize = dfs(neighbor, node, adj, goodNodesCount);
            childSizes[childSubtreeSize]++;
            size += childSubtreeSize;
        }
        
        if (childSizes.size() <= 1) { 
            goodNodesCount++;
        }
        
        return size;
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
       
        for (vector<int>& edge : edges) {
            int u = edge[0], b = edge[1];
            adj[u].push_back(b);
            adj[b].push_back(u);
        }
        
        int goodNodesCount = 0;
        dfs(0, -1, adj, goodNodesCount);
        
        return goodNodesCount;
    }
};
