class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n=apples.size(), day=0, eaten=0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        while(day<n || !pq.empty())
        {
            if(day<n && apples[day]>0)
            {
                pq.push({day+days[day], apples[day]});
            }

            while(!pq.empty() && pq.top().first<=day)
            {
                pq.pop();
            }

            if(!pq.empty())
            {
                auto [expiry, count]=pq.top();
                pq.pop();

                count--;
                eaten++;

                if(count>0)
                {
                    pq.push({expiry, count});
                }
            }

            day++;
        }

        return eaten;
    }
};