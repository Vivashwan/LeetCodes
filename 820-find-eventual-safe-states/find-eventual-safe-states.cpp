class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>reverseGraph(n);

        vector<int>outDegree(n, 0);

        for(int u=0; u<n; u++)
        {
            outDegree[u]=graph[u].size();

            for(auto v: graph[u])
            {
                reverseGraph[v].push_back(u);
            }
        }

        queue<int>q;
        vector<int>safeNodes;

        for(int i=0; i<n; i++)
        {
            if(outDegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            safeNodes.push_back(node);

            for(auto prev: reverseGraph[node])
            {
                outDegree[prev]--;

                if(outDegree[prev]==0)
                {
                    q.push(prev);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};