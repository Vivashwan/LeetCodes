class Solution {
private:
    int MOD = 1e9 + 7;
    long long power(long long x, long long y) 
    {
        long long result = 1;

        while(y>0)
        {
            if(y % 2 == 1) 
            {
                result = (result*x)%MOD;
            }
            y = y/2; 
            x = (x*x)%MOD;
        }

        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long evenCount = (n+1)/2;
        long long primeCount = n/2;

        long long result = (power(5, evenCount) * power(4, primeCount)) % MOD;
        return result;
    }
};