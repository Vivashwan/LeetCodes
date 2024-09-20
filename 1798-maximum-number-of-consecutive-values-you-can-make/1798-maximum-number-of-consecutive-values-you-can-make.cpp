class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int res = 1;
        sort(begin(coins), end(coins));
        for (int coin: coins) {
            if (res >= coin) res += coin;
            else break;
        }
        return res;
    }
};