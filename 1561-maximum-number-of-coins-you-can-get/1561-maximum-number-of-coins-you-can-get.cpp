class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();

        sort(piles.begin(), piles.end());

        int res=0;

        int j = n-2, i = 0;

        while(j>=0)
        {
            res+=piles[j];
            j-=2;

            piles[i]=0;
            i++;
        }

        return res;
    }
};