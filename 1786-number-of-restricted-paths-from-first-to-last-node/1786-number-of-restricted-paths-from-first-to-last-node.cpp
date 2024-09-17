class Solution {
private:
    int MOD = 1e9+7;

    int dfs(int node, int end, vector<int>&dist, unordered_map<int, vector<pair<int, int>>>&adj, vector<int>&dp)
    {
        if(node==end)
        {
            return dp[node]=1;
        }

        if(dp[node]!=-1)
        {
            return dp[node];
        }

        int count=0;

        for(auto it: adj[node])
        {
            if(dist[node]>dist[it.first])
            {
                int path = dfs(it.first, end, dist, adj, dp);
                count = (count+path)%MOD;
            }
        }

        return dp[node]=count;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>>adj;

        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        vector<int>dist(n+1, INT_MAX);

        dist[n] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        pq.push({0, n});

        while(!pq.empty())
        {
            int dis = pq.top().first, node = pq.top().second;
            pq.pop();

            for(auto it: adj[node])
            {
                int adjNode = it.first, adjDist = it.second;

                if(dist[adjNode]>dis+adjDist)
                {
                    dist[adjNode]=dis+adjDist;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        vector<int>dp(n+1, -1);

        return dfs(1, n, dist, adj, dp);
    }
};