class Solution {
private:
    int count=0;

    void dfs(int u, int parent, unordered_map<int, vector<pair<int,int>>>&mp)
    {   
        for(auto it: mp[u])
        {
            int v = it.first;
            int check = it.second;

            if(v!=parent)
            {
                if(check==1)
                {
                    count++;
                }

                dfs(v, u, mp);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int,int>>>mp;

        for(auto it: connections)
        {
            int u = it[0], v = it[1];

            mp[u].push_back({v, 1});
            mp[v].push_back({u, 0});
        }

        dfs(0, -1, mp);

        return count;
    }
};