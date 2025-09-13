class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>>mp;

        for(auto it: dislikes) 
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]); 
        }

        vector<int>color(n+1, -1);

        for(int i=1; i<=n; i++) 
        {  
            if(color[i]==-1) 
            {
                queue<int>q;
                q.push(i);

                color[i]=0;

                while(!q.empty()) 
                {
                    int node=q.front();
                    q.pop();

                    for(auto neighbor: mp[node]) 
                    {
                        if(color[neighbor]==-1)
                        {
                            color[neighbor]=1-color[node];
                            q.push(neighbor);
                        } 
                        else if(color[neighbor]==color[node]) 
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
