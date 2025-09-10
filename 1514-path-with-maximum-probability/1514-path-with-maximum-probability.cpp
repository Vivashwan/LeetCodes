class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>>mp;

        for(int i=0; i<edges.size(); i++)
        {
            mp[edges[i][0]].push_back({edges[i][1], succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>>pq;

        vector<double>maxProb(n, 0.0);

        pq.push({1.0, start_node});
        maxProb[start_node]=1.0;

        while (!pq.empty()) 
        {
            auto [prob, node]=pq.top();
            pq.pop();

            if(node==end_node)
            { 
                return prob;
            }

            for(auto& [neighbor, edgeProb]: mp[node]) 
            {
                double newProb = prob*edgeProb;

                if(newProb>maxProb[neighbor]) 
                {
                    maxProb[neighbor]=newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }        

        return 0.0;
    }
};