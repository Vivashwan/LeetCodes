class Solution {
private:
    vector<vector<vector<int>>> dp;

    void countZeroesOnes(const string &s, int &zeroes, int &ones) {
        zeroes = ones = 0;
        for (char c : s) {
            if (c == '0') zeroes++;
            else ones++;
        }
    }

    int solve(vector<string>& strs, int i, int m, int n) {
        // Base case: If all strings are processed, return 0
        if (i == strs.size()) return 0;

        // If already computed, return stored value
        if (dp[i][m][n] != -1) return dp[i][m][n];

        // Count zeroes and ones in the current string
        int zeroes, ones;
        countZeroesOnes(strs[i], zeroes, ones);

        // Option 1: Skip this string
        int not_take = solve(strs, i + 1, m, n);

        // Option 2: Take this string (only if enough zeroes and ones are left)
        int take = 0;
        if (m >= zeroes && n >= ones) {
            take = 1 + solve(strs, i + 1, m - zeroes, n - ones);
        }

        // Store the result in DP table
        return dp[i][m][n] = max(not_take, take);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        dp.resize(size, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(strs, 0, m, n);
    }
};
