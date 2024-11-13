class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(), piles.end());

        while(k--)
        {
            int val = pq.top();
            pq.pop();

            int newVal = floor(val/2);

            pq.push(val-newVal);
        }

        int sum = 0;

        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }

        return sum;
    }
};