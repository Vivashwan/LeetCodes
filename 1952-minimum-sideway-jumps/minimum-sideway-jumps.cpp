class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, 0));

        // Traverse from second last point to the first point
        for (int i = n - 2; i >= 0; i--) {
            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[i + 1] != lane) {
                    dp[lane][i] = dp[lane][i + 1]; // No side jump needed, carry forward from next point
                } else {
                    int jumpToLane1 = INT_MAX, jumpToLane2 = INT_MAX;
                    if (lane == 1) {
                        if (obstacles[i] != 2) {
                            jumpToLane1 = min(jumpToLane1, 1 + dp[2][i + 1]);
                        }
                        if (obstacles[i] != 3) {
                            jumpToLane2 = min(jumpToLane2, 1 + dp[3][i + 1]);
                        }
                    } else if (lane == 2) {
                        if (obstacles[i] != 1) {
                            jumpToLane1 = min(jumpToLane1, 1 + dp[1][i + 1]);
                        }
                        if (obstacles[i] != 3) {
                            jumpToLane2 = min(jumpToLane2, 1 + dp[3][i + 1]);
                        }
                    } else { // lane == 3
                        if (obstacles[i] != 1) {
                            jumpToLane1 = min(jumpToLane1, 1 + dp[1][i + 1]);
                        }
                        if (obstacles[i] != 2) {
                            jumpToLane2 = min(jumpToLane2, 1 + dp[2][i + 1]);
                        }
                    }
                    dp[lane][i] = min(jumpToLane1, jumpToLane2);
                }
            }
        }
        return dp[2][0]; // Return the minimum side jumps needed to reach lane 2 at the start
    }
};