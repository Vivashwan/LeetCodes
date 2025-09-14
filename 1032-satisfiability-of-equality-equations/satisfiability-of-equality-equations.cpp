class Solution {
private:
    void dfs(int a, vector<bool>&visited, unordered_map<int, vector<int>>&mp)
    {
        visited[a]=true;

        for(auto it: mp[a])
        {
            if(!visited[it])
            {
                dfs(it, visited, mp);
            }
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<int, vector<int>>mp;

        for(auto it: equations)
        {
            if(it[1]=='=')
            {
                mp[it[0]-'a'].push_back(it[3]-'a');
                mp[it[3]-'a'].push_back(it[0]-'a');
            }
        }

        for(auto it: equations)
        {
            if(it[1]=='!')
            {
                int a=it[0]-'a', b=it[3]-'a';

                vector<bool>visited(27, false);

                dfs(a, visited, mp);

                if(visited[b]==true)
                {
                    return false;
                }
            }
        }

        return true;
    }
};