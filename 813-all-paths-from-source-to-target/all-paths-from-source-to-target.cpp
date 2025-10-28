class Solution {
private:
    void dfs(vector<vector<int>>&adj, vector<int>&temp, vector<vector<int>>& res, int ind, int n)
    {
        if(ind==n-1)
        {
            res.push_back(temp);
            return;
        }

        for(auto it: adj[ind])
        {
            temp.push_back(it);
            dfs(adj, temp, res, it, n);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>res;
        vector<int>temp;
        temp.push_back(0);

        dfs(graph, temp, res, 0, n);

        return res;
    }
};
