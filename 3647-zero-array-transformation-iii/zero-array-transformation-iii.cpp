class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        // Sort queries by l
        sort(queries.begin(), queries.end());

        // Max-heap by r (farthest end first)
        priority_queue<int> pq; // stores r

        // Min-heap for active selected queries' ending positions
        priority_queue<int, vector<int>, greater<int>> active; // stores r

        int qi = 0;      // pointer in queries
        int used = 0;    // how many queries we select

        for (int i = 0; i < n; i++) {
            // Add all queries that start at or before i
            while (qi < m && queries[qi][0] <= i) {
                pq.push(queries[qi][1]);
                qi++;
            }

            // Remove expired active queries
            while (!active.empty() && active.top() < i) {
                active.pop();
            }

            // Ensure we have at least nums[i] active queries covering i
            while ((int)active.size() < nums[i]) {
                // Remove unusable candidates from pq
                while (!pq.empty() && pq.top() < i) {
                    pq.pop();
                }
                if (pq.empty()) {
                    return -1; // cannot satisfy demand at i
                }
                int r = pq.top(); pq.pop();
                active.push(r);
                used++;
            }
        }

        return m - used;
    }
};
