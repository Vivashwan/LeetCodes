class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();

        vector<vector<int>>adj(n);
        vector<int>time(n, -1);

        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int>q;

        q.push(0);

        time[0]=0;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            for(auto v: adj[it])
            {
                if(time[v]==-1)
                {
                    time[v]=time[it]+1;
                    q.push(v);
                }
            }
        }

        int res=0;

        for(int i=1; i<n; i++)
        {
            int extra = (time[i]*2-1)/patience[i];

            int lastRequest = extra*patience[i];

            int lastOutput = lastRequest+time[i]*2;

            res = max(res, lastOutput);            
        }

        return res+1;
    }
};