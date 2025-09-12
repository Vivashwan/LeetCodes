class Solution {
private:
    void dfs(string& email, vector<vector<string>>&res, unordered_set<string>&visited, unordered_map<string, vector<string>>&adj)
    {
        visited.insert(email);
        res.back().push_back(email);

        for(auto it: adj[email])
        {
            if(visited.count(it)==0)
            {
                dfs(it, res, visited, adj);
            }
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>>adj;

        for(auto it: accounts)
        {
            for(int i=2; i<it.size(); i++)
            {
                adj[it[i-1]].push_back(it[i]);
                adj[it[i]].push_back(it[i-1]);
            }
        }

        vector<vector<string>>res;

        unordered_set<string>visited;

        for(auto it: accounts)
        {
            if(visited.count(it[1])==0)
            {
                res.push_back({it[0]});

                dfs(it[1], res, visited, adj);

                sort(begin(res.back())+1, end(res.back()));
            }
        }

        return res;
    }
};