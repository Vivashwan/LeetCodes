class Solution {
private:
    int func(vector<int>& nums, int n, int target, int ind, vector<vector<int>>& dp, int offset) {
        if (ind == n) {
            return (target == 0) ? 1 : 0;
        }

        if (dp[ind][target + offset] != -1) {
            return dp[ind][target + offset];
        }

        int pos = func(nums, n, target - nums[ind], ind + 1, dp, offset);
        int neg = func(nums, n, target + nums[ind], ind + 1, dp, offset);

        return dp[ind][target + offset] = pos + neg;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;

        if (abs(target) > sum) return 0;

        int offset = 1000;
        vector<vector<int>> dp(n + 1, vector<int>(3002, -1));

        return func(nums, n, target, 0, dp, offset);
    }
};
