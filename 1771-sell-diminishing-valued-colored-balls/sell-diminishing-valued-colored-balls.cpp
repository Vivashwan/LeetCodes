class Solution {
private:
    int MOD = 1e9+7;
public:
    int maxProfit(vector<int>& v, int orders) {
        sort(v.begin(), v.end());

        int n = v.size();
        long long res=0;
        for(int i=n-1; i>=0; i--)
        {
            long long diff = v[i]-(i>0 ? v[i-1]:0);

            long long x = min((long long)orders, (n-i)*diff);

            long long r = v[i], l = r-x/(n-i);

            res+=(r*(r+1)/2-l*(l+1)/2)*(n-i);
            res%=MOD;

            res+=l*(x%(n-i));

            res%=MOD;

            orders-=x;
        }

        return res;
    }
};