class Solution {
private:
    int count=0;

    void func(int u, unordered_map<int, vector<pair<int, int>>>&mp, vector<bool>&visited)
    {
        visited[u]=true;

        for(auto it: mp[u])
        {
            int nextNode=it.first, dir=it.second;

            if(!visited[nextNode])
            {
                count+=dir;
                func(nextNode, mp, visited);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>>mp;

        for(auto it: connections)
        {
            int from=it[0], to=it[1];

            mp[from].push_back({to, 1});
            mp[to].push_back({from, 0});
        }

        vector<bool>visited(n, false);

        func(0, mp, visited);

        return count;
    }
};