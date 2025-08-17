class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int>mp;

        for(auto it: tasks)
        {
            mp[it]++;
        }
        
        priority_queue<int>pq;

        for(auto it:mp)
        {
            pq.push(it.second);
        }

        int time=0;

        while(!pq.empty())
        {
            vector<int>slot;

            for(int i=0; i<=n; i++)
            {
                if(!pq.empty())
                {
                    slot.push_back(pq.top()-1);
                    pq.pop();
                }
            }

            for(auto it: slot)
            {
                if(it>0)
                {
                    pq.push(it);
                }
            }

            if(pq.empty())
            {
                time+=slot.size();
            }
            else time+=n+1;
        }

        return time;
    }
};