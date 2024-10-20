class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        vector<int>ans;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> busy;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>free;

        for(int i=0; i<n; i++)
        {
            free.push({servers[i], i});
        } 

        for(int time=0; time<m; time++)
        {
            while(!busy.empty()) 
            {
                auto [sec, wt, ind] = busy.top();

                if(sec > time)
                { 
                    break;
                }

                busy.pop();
                free.push({wt, ind});
            }

            if(free.empty())
            {
                auto [sec, wt, ind] = busy.top();
                busy.pop();

                busy.push({sec+tasks[time], wt, ind});
                ans.push_back(ind);
            }
            else
            {
                auto [wt, ind] = free.top();
                free.pop();

                busy.push({time+tasks[time], wt, ind});
                ans.push_back(ind);
            }
        }

        return ans;
    }
};