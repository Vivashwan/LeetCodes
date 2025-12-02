class Solution {
private:
    int count=0;

    void func(int ind, unordered_map<int, vector<pair<int, int>>>&mp, vector<bool>&visited)
    {
        visited[ind]=true;

        for(auto it: mp[ind])
        {
            if(!visited[it.first])
            {
                count+=it.second;
                func(it.first, mp, visited);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>>mp;

        for(auto it: connections)
        {
            mp[it[0]].push_back({it[1], 1});
            mp[it[1]].push_back({it[0], 0});
        }

        vector<bool>visited(n, false);

        func(0, mp, visited);

        return count;
    }
};