class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n, 0);

        unordered_set<string>directRoads;
        
        for(auto& road: roads) 
        {
            int u=road[0], v=road[1];

            degree[u]++, degree[v]++;
            
            string key=to_string(min(u, v))+"_"+to_string(max(u, v));

            directRoads.insert(key);
        }
        
        int maxRank=0;
        
        for(int i=0; i<n; i++) 
        {
            for(int j=i+1; j<n; j++) 
            {
                int rank=degree[i]+degree[j];
                
                string key=to_string(i)+"_"+to_string(j);

                if(directRoads.count(key)) 
                {
                    rank--;
                }
                
                maxRank=max(maxRank, rank);
            }
        }
        
        return maxRank;
    }
};
