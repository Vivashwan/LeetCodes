class Solution {
private:
    int solve(int n, int amount, vector<int>& coins, vector<vector<double>>& dp) {
        // Base Case: Fill last row (index = n-1) based on the last coin
        for (int i = 0; i <= amount; i++) {
            if (i % coins[n - 1] == 0) {
                dp[n - 1][i] = 1;
            } else {
                dp[n - 1][i] = 0;
            }
        }

        // Iterate from index = n - 2 down to 0
        for (int index = n - 2; index >= 0; index--) {
            for (int target = 0; target <= amount; target++) {
                double notPick = dp[index + 1][target]; // Take the value from the next row
                double pick = 0;

                if (coins[index] <= target) {
                    pick = dp[index][target - coins[index]]; // Stay in the same row for picking
                }

                dp[index][target] = notPick + pick;
            }
        }

        return dp[0][amount];
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<double>> dp(n, vector<double>(amount + 1, 0));
        return solve(n, amount, coins, dp);
    }
};
