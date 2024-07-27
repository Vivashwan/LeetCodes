class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        vector<pair<int, int>> vc(n);
        for (int i = 0; i < n; ++i)
            vc[i] = {ages[i], scores[i]};
        
        sort(vc.begin(), vc.end());

        vector<vector<int>> memo(n, vector<int>(n, -1)); // Memoization table
        return highestScore(vc, 0, -1, memo);
    }

    int highestScore(vector<pair<int, int>>& vc, int currentIndex, int lastIndex, vector<vector<int>>& memo) {
        if (currentIndex == vc.size())
            return 0;
        
        if (lastIndex != -1 && memo[currentIndex][lastIndex] != -1)
            return memo[currentIndex][lastIndex];

        int include = 0;
        if (lastIndex == -1 || vc[currentIndex].second >= vc[lastIndex].second) {
            include = vc[currentIndex].second + highestScore(vc, currentIndex + 1, currentIndex, memo);
        }
        
        int exclude = highestScore(vc, currentIndex + 1, lastIndex, memo);
        
        int maxScore = max(include, exclude);

        if (lastIndex != -1)
            memo[currentIndex][lastIndex] = maxScore;

        return maxScore;
    }
};
