class Solution {
private:
    int MOD = 1e9+7;

    int numberOfBits(int i)
    {
        return log2(i)+1;
    }
public:
    int concatenatedBinary(int n) {
        long ans = 0;

        for(int i=1; i<=n; i++)
        {
            int len = numberOfBits(i);

            ans = ((ans<<len)%MOD+i)%MOD;
        }

        return ans;
    }
};