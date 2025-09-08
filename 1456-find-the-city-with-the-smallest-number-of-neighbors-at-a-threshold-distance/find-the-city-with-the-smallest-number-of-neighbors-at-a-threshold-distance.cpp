class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>>adj(n);

        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int minNeighbors=n, res=0;

        for(int i=0; i<n; i++)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;

            vector<int>dist(n, INT_MAX);

            pq.push({0, i});

            dist[i]=0;

            while(!pq.empty())
            {
                auto [d, u]=pq.top();
                pq.pop();

                if(d>dist[u])
                {
                    continue;
                }

                for(auto it: adj[u])
                {
                    auto [v, wt]=it;

                    if(dist[u]+wt < dist[v])
                    {
                        dist[v]=dist[u]+wt;

                        pq.push({dist[v], v});
                    }
                }
            }

            int count=0;

            for(int j=0; j<n; j++)
            {
                if(j!=i && dist[j]<=distanceThreshold)
                {
                    count++;
                }
            }

            if(count<=minNeighbors)
            {
                minNeighbors=count;
                res=i;
            }

        }

        return res;
    }
};