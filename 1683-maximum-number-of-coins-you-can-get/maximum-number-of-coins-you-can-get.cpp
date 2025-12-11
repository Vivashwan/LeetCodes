class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();

        sort(piles.begin(), piles.end());

        int bobPointer=0, playerPointer=n-2;

        int total=0;

        while(bobPointer<playerPointer)
        {
            total+=piles[playerPointer];
            playerPointer-=2;
            bobPointer++;
        }

        return total;
    }
};