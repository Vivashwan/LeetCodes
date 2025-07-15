class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int, vector<int>>pq;

            for(auto it: nums)
            {
                pq.push(it);
            }
      
            int i = 0;
            while(i<k-1)
            {
                pq.pop();
                i++;
            }

            int ans = pq.top();
            pq.empty();

            return ans;
    }
};