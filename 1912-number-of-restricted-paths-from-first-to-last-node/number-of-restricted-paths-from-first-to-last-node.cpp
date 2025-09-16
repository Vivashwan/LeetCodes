class Solution {
private:
    vector<int>dist, memo;
    vector<vector<pair<int, int>>>graph;

    int MOD=1e9+7;

    int dfs(int node, int n) 
    {
        if(node==n)
        { 
            return 1;
        }

        if(memo[node]!=-1)
        { 
            return memo[node];
        }

        long long paths=0;

        for(auto& [nei, w]: graph[node]) 
        {
            if(dist[node]>dist[nei]) 
            {
                paths=(paths+dfs(nei, n))%MOD;
            }
        }

        return memo[node]=paths;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        graph.resize(n+1);

        for(auto& edge: edges) 
        {
            int u=edge[0], v=edge[1], w=edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        dist.resize(n+1, INT_MAX);
        dist[n]=0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        pq.push({0, n});

        while(!pq.empty()) 
        {
            auto [d, node]=pq.top(); 
            pq.pop();

            if(d>dist[node])
            { 
                continue;
            }

            for(auto& [nei, w]: graph[node]) 
            {
                if(dist[nei]>d+w) 
                {
                    dist[nei]=d+w;

                    pq.push({dist[nei], nei});
                }
            }
        }

        memo.assign(n+1, -1);

        return dfs(1, n);
    }
};
