class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>>pq;
        unordered_set<long>seen;

        pq.push(1);
        seen.insert(1);

        long currentUgly;

        for(int i=1; i<=n; i++)
        {
            currentUgly=pq.top();
            pq.pop();

            for(auto it: {2, 3, 5})
            {
                long nextUgly=currentUgly*it;

                if(seen.find(nextUgly)==seen.end())
                {
                    seen.insert(nextUgly);
                    pq.push(nextUgly);
                }
            }
        }

        return (int)currentUgly;
    }
};