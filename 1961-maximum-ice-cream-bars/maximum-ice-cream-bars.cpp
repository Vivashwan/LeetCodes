class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>v(100001, 0);
        int i, res=0;

        for(auto c: costs)
        {
            v[c]++;
        }

        for(int i=1; i<=min(100000, coins); i++)
        {
            int canBuy = min(v[i], coins/i);
            coins-=canBuy*i;
            res+=canBuy;
        }
        
        return res;
    }
};