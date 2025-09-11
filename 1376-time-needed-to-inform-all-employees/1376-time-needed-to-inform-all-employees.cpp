class Solution {
public:
    vector<vector<int>>adj;
    
    int dfs(int u, vector<int>&informTime) 
    {
        int maxTime=0;
        for(int v: adj[u]) 
        {
            maxTime=max(maxTime, dfs(v, informTime));
        }
        
        return informTime[u]+maxTime;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n);
        
        for(int i=0; i<manager.size(); i++) 
        {
            if(manager[i]!=-1) 
            {
                adj[manager[i]].push_back(i);
            }
        }

        return dfs(headID, informTime);
    }
};
