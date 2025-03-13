class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), l = s3.size();
        if (n + m != l) return false;

        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(m + 1, vector<bool>(l + 1, false)));
        
        dp[0][0][0] = true;
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= l; k++) {
                    if (i + j != k) continue;

                    if (i > 0 && s1[i - 1] == s3[k - 1]) {
                        dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k - 1];
                    }
                    if (j > 0 && s2[j - 1] == s3[k - 1]) {
                        dp[i][j][k] = dp[i][j][k] || dp[i][j - 1][k - 1];
                    }
                }
            }
        }

        return dp[n][m][l]; 
    }
};