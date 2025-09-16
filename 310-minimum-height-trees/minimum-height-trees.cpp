class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        { 
            return {0};
        }

        unordered_map<int, vector<int>>mp;

        vector<int>degree(n, 0);

        for(auto it: edges)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);

            degree[it[0]]++;
            degree[it[1]]++;
        }

        queue<int>q;

        for(int i=0; i<n; i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }

        int remainingNodes=n;

        while(remainingNodes>2)
        {
            int size=q.size();

            remainingNodes-=size;

            for(int i=0; i<size; i++)
            {
                auto it=q.front();
                q.pop();

                for(auto u: mp[it])
                {
                    degree[u]--;

                    if(degree[u]==1)
                    {
                        q.push(u);
                    }
                }
            }
        }

        vector<int>res;

        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};