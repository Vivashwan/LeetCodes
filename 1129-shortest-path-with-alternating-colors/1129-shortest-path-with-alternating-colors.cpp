class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>redAdj(n), blueAdj(n);

        vector<vector<bool>>visited(n, vector<bool>(2, false));

        for(auto it: redEdges)
        {
            redAdj[it[0]].push_back(it[1]);
        }

        for(auto it: blueEdges)
        {
            blueAdj[it[0]].push_back(it[1]);
        }

        vector<int>res(n, -1);

        queue<tuple<int, int, int>>q;

        q.push({0, 0, -1});

        while(!q.empty())
        {
            auto [node, steps, color]=q.front();
            q.pop();

            if(res[node]==-1)
            {
                res[node]=steps;
            }

            if(color!=0)
            {
                for(auto it: redAdj[node])
                {
                    if(!visited[it][0])
                    {
                        visited[it][0]=true;
                        q.push({it, steps+1, 0});
                    }
                }
            }

            if(color!=1)
            {
                for(auto it: blueAdj[node])
                {
                    if(!visited[it][1])
                    {
                        visited[it][1]=true;
                        q.push({it, steps+1, 1});
                    }
                }
            }
        }

        return res;
    }
};