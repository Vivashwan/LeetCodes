class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        pq.push({0, 0});

        vector<bool>visited(n, false);

        int totalCost=0, edgesUsed=0;

        while(edgesUsed<n) 
        {
            auto [cost, u]=pq.top();
            pq.pop();

            if(visited[u])
            { 
                continue;
            }

            visited[u]=true;
            totalCost+=cost;
            edgesUsed++;

            for(int v=0; v<n; v++) 
            {
                if(!visited[v]) 
                {
                    int dist=abs(points[u][0]-points[v][0]) + abs(points[u][1]-points[v][1]);
                    pq.push({dist, v});
                }
            }
        }

        return totalCost;
    }
};