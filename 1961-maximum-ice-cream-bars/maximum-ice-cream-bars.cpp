class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>temp(100001, 0);

        int res=0;

        for(auto it: costs)
        {
            temp[it]++;
        }

        for(int i=1; i<=min(100000, coins); i++)
        {
            int canBuy=min(temp[i], coins/i);
            coins-=canBuy*i;
            res+=canBuy;
        }

        return res;
    }
};