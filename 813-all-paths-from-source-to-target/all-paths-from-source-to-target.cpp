class Solution {
private:
    void func(int u, int target, vector<int>temp, vector<vector<int>>&res, vector<vector<int>>&graph)
    {
        temp.push_back(u);

        if(u==target)
        {
            res.push_back(temp);
            return;
        }

        for(auto v: graph[u])
        {
            func(v, target, temp, res, graph);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>res;

        for(auto u: graph[0])
        {
            vector<int>temp;

            temp.push_back(0);

            func(u, n-1, temp, res, graph);
        }

        return res;
    }
};