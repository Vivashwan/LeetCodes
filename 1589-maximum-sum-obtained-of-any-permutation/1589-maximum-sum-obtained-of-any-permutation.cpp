class Solution {
private:
    int mod = 1e9+7;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> ind(n+1, 0);

        // Apply the difference array method
        for (auto& req : requests) {
            ind[req[0]]++;
            if (req[1] + 1 < n) ind[req[1] + 1]--;
        }

        // Convert difference array to prefix sum array
        for (int i = 1; i < n; i++) {
            ind[i] += ind[i-1];
        }

        // Remove the extra element used for boundary conditions
        ind.pop_back();

        // Sort the nums and the frequency array
        sort(nums.begin(), nums.end());
        sort(ind.begin(), ind.end());

        // Calculate the maximum sum using the sorted arrays
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + (long long) ind[i] * nums[i]) % mod;
        }

        return sum;
    }
};
