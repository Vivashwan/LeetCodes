class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>>mp;

        for(auto it: times) 
        {
            mp[it[0]].push_back({it[1], it[2]});
        }

        vector<int>miniTime(n+1, INT_MAX);

        miniTime[k]=0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if(time>miniTime[node])
            { 
                continue;
            }

            for(auto [nextNode, edgeTime]: mp[node]) 
            {
                if(time+edgeTime<miniTime[nextNode]) 
                {
                    miniTime[nextNode]=time+edgeTime;

                    pq.push({miniTime[nextNode], nextNode});
                }
            }
        }

        int maxim=0;

        for(int i=1; i<=n; i++) 
        {
            if(miniTime[i]==INT_MAX)
            { 
                return -1;
            }

            maxim=max(maxim, miniTime[i]);
        }

        return maxim;
    }
};