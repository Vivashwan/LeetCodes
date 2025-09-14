class Solution {
private:
    void dfs(int u, vector<bool>&visited, vector<int>&connectedComponents, unordered_map<int, vector<int>>&mp)
    {
        visited[u]=true;
        connectedComponents.push_back(u);

        for(auto it: mp[u])
        {
            if(!visited[it])
            {
                dfs(it, visited, connectedComponents, mp);
            }
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();

        unordered_map<int, vector<int>>mp;

        for(auto it: allowedSwaps)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        vector<bool>visited(n, false);

        int hammingDistance=0;

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                vector<int>connectedComponents;

                dfs(i, visited, connectedComponents, mp);

                unordered_map<int, int>countSources, countTarget;

                for(auto it: connectedComponents)
                {
                    countSources[source[it]]++;
                    countTarget[target[it]]++;
                }

                for(auto& [it, freq]: countSources)
                {
                    if(countTarget.count(it))
                    {
                        int mini=min(freq, countTarget[it]);

                        countSources[it]-=mini;
                        countTarget[it]-=mini;
                    }
                }

                for(auto& [it, freq]: countSources)
                {
                    hammingDistance+=freq;
                }
            }
        }

        return hammingDistance;
    }
};