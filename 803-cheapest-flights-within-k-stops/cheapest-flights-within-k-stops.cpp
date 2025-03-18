class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>>adj;

        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;

        pq.push({0, src, 0});

        vector<int>visited(n+1, INT_MAX);

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();

            int cost=it[0], curr=it[1], stops=it[2];

            if(curr==dst)
            {
                return cost;
            }

            if(visited[curr]<stops)
            {
                continue;
            }

            visited[curr]=stops;

            if(stops>k)
            {
                continue;
            }

            for(auto v: adj[curr])
            {
                pq.push({v.second+cost, v.first, stops+1});
            }            
        }

        return -1;
    }
};