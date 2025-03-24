class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int> counts = {0, 0};
        for (auto p : position)
            counts[p % 2] += 1;
        return min(counts[0], counts[1]);
    }
};