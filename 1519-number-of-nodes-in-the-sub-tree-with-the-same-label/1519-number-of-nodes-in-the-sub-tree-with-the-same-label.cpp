class Solution {
private:
    vector<int> func(vector<vector<int>>&adj, string& labels, vector<int>&res, int ind)
    {
        vector<int>ans(26, 0);

        res[ind] = 1;

        ans[labels[ind]-'a'] = 1;

        for(int j=0; j<adj[ind].size(); j++)
        {
            if(!res[adj[ind][j]]) // if not parent
            {
                vector<int>temp = func(adj, labels, res, adj[ind][j]);
                
                for(int k=0; k<26; k++)
                {
                    ans[k]+=temp[k];
                }
            }
        }

        res[ind] = ans[labels[ind]-'a'];

        return ans;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);

        vector<int>res(n, 0);

        int m = edges.size();

        for(int i=0; i<m; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        func(adj, labels, res, 0);

        return res;
    }
};