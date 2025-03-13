class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill the table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                // Skip current element
                int skip = dp[i + 1][prev + 1];

                // Include current element if it's valid
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i + 1];
                }

                dp[i][prev + 1] = max(skip, take);
            }
        }

        return dp[0][0]; // LIS length starting from index 0
    }
};
