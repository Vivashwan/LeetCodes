class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res=0;

        priority_queue<int>pq;

        for(auto it: nums)
        {
            pq.push(it);
        }

        while(k--)
        {   
            auto it=pq.top();
            pq.pop();

            res+=it;

            pq.push((it+2)/3);
        }

        return res;
    }
};