class Solution {
private:
    bool dfs(int start, int end, unordered_map<int, vector<int>>&mp, vector<bool>&visited)
    {
        if(start==end)
        {
            return true;
        }

        visited[start]=true;

        for(auto it: mp[start])
        {
            if(!visited[it])
            {
                if(dfs(it, end, mp, visited)==true)
                {
                    return true;
                }
            }
        }

        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>>mp;

        for(auto it: prerequisites)
        {
            mp[it[0]].push_back(it[1]);
        }

        vector<bool>res;

        for(auto it: queries)
        {
            int start=it[0], end=it[1];

            if(mp.find(start)==mp.end())
            {
                res.push_back(false);
            }
            else
            {
                vector<bool>visited(numCourses, false);

                bool state=dfs(start, end, mp, visited);

                res.push_back(state);
            }
        }

        return res;
    }
};