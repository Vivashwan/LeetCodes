class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> ratio_counts;
        long long res = 0;

        for (auto& rectangle: rectangles)
        {
            double ratio = static_cast<double>(rectangle.front()) / rectangle.back();
            res += ratio_counts[ratio]++;
        }
        
        return res;
    }
};