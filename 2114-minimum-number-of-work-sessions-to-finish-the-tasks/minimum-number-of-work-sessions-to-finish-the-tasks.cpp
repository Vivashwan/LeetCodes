class Solution {
private:
    int mini;
    void func(vector<int>&tasks, int sessionTime, vector<int>&sessions, int n, int ind)
    {
        if(sessions.size()>=mini)
        {
            return;
        }

        if(ind==n)
        {
            int size=sessions.size();
            mini=min(mini, size);
            return;
        }

        int task=tasks[ind];

        for(int i=0; i<sessions.size(); i++)
        {
            if(sessions[i]+task<=sessionTime)
            {
                sessions[i]+=task;
                func(tasks, sessionTime, sessions, n, ind+1);
                sessions[i]-=task;
            }
        }

        sessions.push_back(task);
        func(tasks, sessionTime, sessions, n, ind+1);
        sessions.pop_back();
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();

        mini=n;

        vector<int>sessions;

        func(tasks, sessionTime, sessions, n, 0);

        return mini;
    }
};