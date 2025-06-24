typedef long long ll;

class Solution {
private:
    ll gcd(ll a, ll b)
    {
        if(a==0)
        {
            return b;
        }

        return gcd(b%a, a);
    }

    ll lcm(ll a, ll b)
    {
        return a*b/gcd(a, b);
    }

    int countUglyNumbers(ll mid, ll a, ll b, ll c)
    {
        return (int) mid/a+mid/b+mid/c-mid/lcm(a,b)-mid/lcm(a,c)-mid/lcm(b,c)+mid/lcm(a, lcm(b, c));
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int left=0, right=2e9, res=0;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(countUglyNumbers(mid, a, b, c)>=n)
            {
                res=mid;
                right=mid-1;
            }
            else left=mid+1;
        }

        return res;
    }
};