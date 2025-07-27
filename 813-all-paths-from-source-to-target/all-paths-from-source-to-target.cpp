class Solution {
private:
    void func(vector<int>&vertices, int target, vector<vector<int>>&res, vector<int>temp, vector<int>&visited, int n, vector<vector<int>>&adj)
    {
        for(auto it: vertices)
        {
            if(it==target)
            {
                temp.push_back(it);

                res.push_back(temp);

                temp.pop_back();
            }
            else if(!visited[it])
            {
                visited[it]=true;
                temp.push_back(it);

                func(adj[it], target, res, temp, visited, n, adj);

                temp.pop_back();
                visited[it]=false;
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        int target=n-1;

        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++)
        {
            adj[i].insert(adj[i].end(), graph[i].begin(), graph[i].end());
        }

        vector<vector<int>>res;

        vector<int>temp, visited(n);

        temp.push_back(0);

        func(adj[0], target, res, temp, visited, n, adj);

        return res;
    }
};