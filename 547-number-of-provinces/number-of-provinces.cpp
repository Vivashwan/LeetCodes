class Solution {
private:
    void func(unordered_map<int, vector<int>>&mp, vector<bool>&visited, int ind)
    {
        visited[ind]=true;

        for(auto it: mp[ind])
        {
            if(!visited[it])
            {
                func(mp, visited, it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), m=isConnected[0].size();

        unordered_map<int, vector<int>>mp;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    mp[i].push_back(j);
                }
            }
        }

        vector<bool>visited(n, false);

        int count=0;

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                count++;

                func(mp, visited, i);
            }
        }

        return count;
    }
};