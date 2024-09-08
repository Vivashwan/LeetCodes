class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a + b > c && a + c > b && c + b > a) return (a + b + c) / 2;
        return a + b + c - max({a, b, c});
    }
};