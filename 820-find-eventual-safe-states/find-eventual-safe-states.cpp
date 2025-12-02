class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>reversedGraph(n);

        vector<int>outDegree(n, 0);

        for(int u = 0; u < n; u++)
        {
            outDegree[u] = graph[u].size();
            for (int v : graph[u])
            {
                reversedGraph[v].push_back(u);
            }
        }

        queue<int>q;

        for(int i=0; i<n; i++)
        {
            if(outDegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int>res;

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            res.push_back(it);

            for(auto v: reversedGraph[it])
            {
                outDegree[v]--;

                if(outDegree[v]==0)
                {
                    q.push(v);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};