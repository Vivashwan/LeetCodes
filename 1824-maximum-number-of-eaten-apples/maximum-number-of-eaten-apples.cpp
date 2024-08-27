class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size(), count = 0, i = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;

        while(i<n || !pq.empty())
        {
            if(i<n && apples[i]>0)
            {
                pq.push({i+days[i], apples[i]});
            }

            while(!pq.empty() && (pq.top().first<=i || pq.top().second<=0))
            {
                pq.pop();
            }

            if(!pq.empty())
            {
                auto it = pq.top();
                pq.pop();

                count++;

                it.second-=1;

                if(it.second>0)
                {
                    pq.push(it);
                }
            }

            i++;
        }

        return count;
    }
};