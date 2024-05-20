class Solution {
private:
    bool dfs(unordered_map<int, vector<int>>&mp, int a, int b, vector<vector<int>>&dp)
    {
        if(dp[a][b]!=-1)
        {
            return dp[a][b];
        }

        for(int i=0; i<mp[a].size(); i++)
        {
            if(mp[a][i]==b || dfs(mp, mp[a][i], b, dp))
            {
                return dp[a][b] = true;
            }
        }

        return dp[a][b] = false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>>mp;
        vector<vector<int>>dp(numCourses, vector<int>(numCourses, -1));

        for(int i=0; i<prerequisites.size(); i++)
        {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            dp[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }

        vector<bool>res;

        for(int i=0; i<queries.size(); i++)
        {
            bool p = dfs(mp, queries[i][1], queries[i][0], dp);
            res.push_back(p);
        }

        return res;
    }
};