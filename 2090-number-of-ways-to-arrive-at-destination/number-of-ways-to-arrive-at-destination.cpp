class Solution {
private:
    int MOD=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>>adj;

        for(auto& road: roads)
        {
            int u=road[0], v=road[1], time=road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
        
        vector<long long>dist(n, LLONG_MAX);
        vector<int>ways(n, 0);

        dist[0]=0, ways[0]=1;
        
        pq.push({0, 0});

        while(!pq.empty()) 
        {
            auto [d, u]=pq.top();
            pq.pop();

            if(d>dist[u])
            { 
                continue;
            }

            for(auto& [v, time]: adj[u]) 
            {
                if(dist[v]>d+time) 
                {
                    dist[v]=d+time;
                    ways[v]=ways[u];
                    pq.push({dist[v], v});
                } 
                else if(dist[v]==d+time) 
                {
                    ways[v]=(ways[v]+ways[u])%MOD;
                }
            }
        }

        return ways[n-1];
    }
};