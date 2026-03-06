class Solution {
private:
    int MOD=1e9+7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>pq;

        for(auto it: nums)
        {
            pq.push(it);
        }

        while(k--)
        {
            auto it=pq.top();
            pq.pop();

            it++;

            pq.push(it);
        }

        int res=1;

        while(!pq.empty())
        {   
            res=(res*pq.top())%MOD;
            pq.pop();
        }

        return res%MOD;
    }
};