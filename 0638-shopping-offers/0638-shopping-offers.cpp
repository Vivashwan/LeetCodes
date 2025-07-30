class Solution {
private:
    map<vector<int>, int>mp;
    bool noNegatives(vector<int>&needs)
    {
        for(auto it: needs)
        {
            if(it<0)
            {
                return false;
            }
        }

        return true;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(mp[needs])
        {
            return mp[needs];
        }
        int n = price.size(), m = needs.size();
        int bestOffers = 0;

        for(int i=0; i<n; i++)
        {
            bestOffers+=price[i]*needs[i];
        }

        for(auto it: special)
        {
            for(int i=0; i<m; i++)
            {
                needs[i]-=it[i];
            }

            if(noNegatives(needs))
            {
                int withOffers = it.back()+shoppingOffers(price, special, needs);
                bestOffers = min(bestOffers, withOffers);
            }

            for(int i=0; i<m; i++)
            {
                needs[i]+=it[i];
            }
        }

        return mp[needs] = bestOffers;
    }
};