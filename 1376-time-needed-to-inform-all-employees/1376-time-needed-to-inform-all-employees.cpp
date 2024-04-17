class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>>mp;

        for(int i=0; i<manager.size(); i++)
        {
            mp[manager[i]].push_back(i);
        }

        queue<pair<int, int>>q;

        q.push({headID, 0});

        int maxi = INT_MIN;

        while(!q.empty())
        {
            int n = q.size();

            for(int i=0; i<n; i++)
            {
                int head = q.front().first;

                int timeTaken = q.front().second;

                q.pop();

                int dur = informTime[head]+timeTaken;
                maxi = max(dur, maxi);

                for(auto it: mp[head])
                {
                    q.push({it, dur});
                }
            }
        }

        return maxi;
    }
};