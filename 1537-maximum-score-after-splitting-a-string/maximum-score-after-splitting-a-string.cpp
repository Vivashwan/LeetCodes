class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        
        int leftZeroes = 0, rightOnes = 0, res = 0;

        for (char c : s) {
            if (c == '1') rightOnes++;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                leftZeroes++;
            } else {
                rightOnes--;
            }

            res = max(res, leftZeroes + rightOnes);
        }

        return res;
    }
};
