class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<array<int, 3>>sortedTasks;

        for(int i=0; i<n; i++)
        {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());

        vector<int>res;

        long long currTime = 0;
        int index = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        while(index<n || !pq.empty())
        {
            if(pq.empty() && currTime<sortedTasks[index][0])
            {
                currTime = sortedTasks[index][0];
            }

            while(index<n && sortedTasks[index][0] <= currTime)
            {
                pq.push({sortedTasks[index][1], sortedTasks[index][2]});
                index++;
            }

            auto it = pq.top();
            pq.pop();

            currTime += it.first;

            res.push_back(it.second);
        }

        return res;
    }
};