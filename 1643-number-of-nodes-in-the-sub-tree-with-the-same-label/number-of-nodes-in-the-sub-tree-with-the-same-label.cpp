class Solution {
private:
    vector<int> dfs(int u, int parent, vector<vector<int>>&adj, vector<int>&res, string &labels)
    {
        vector<int>freq(26, 0);

        freq[labels[u]-'a']++;

        for(auto v: adj[u])
        {
            if(v==parent)
            {
                continue;
            }

            vector<int>childFreq=dfs(v, u, adj, res, labels);

            for(int i=0; i<26; i++)
            {
                freq[i]+=childFreq[i];
            }
        }

        res[u]=freq[labels[u]-'a'];

        return freq;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);

        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>res(n, 0);

        dfs(0, -1, adj, res, labels);

        return res;
    }
};