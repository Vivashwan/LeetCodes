class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) { 
        unordered_map<int, set<int>> mp; 

        for(int i = 0; i < roads.size(); i++) 
        {
            int u = roads[i][0], v = roads[i][1];
            mp[u].insert(v);
            mp[v].insert(u);
        }

        int maxim = 0;

        for(int i = 0; i < n; i++) 
        {
            for(int j = i + 1; j < n; j++) 
            {
                int currentRank = mp[i].size() + mp[j].size();

                if (mp[i].find(j) != mp[i].end()) 
                {
                    currentRank--;
                }
                
                maxim = max(maxim, currentRank);
            }
        }

        return maxim;
    }
};