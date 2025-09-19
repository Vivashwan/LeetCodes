class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
        {
            return 1;
        }

        int temp=n, mask=0;

        while(temp)
        {
            mask<<=1;
            mask|=1;
            temp>>=1;
        }

        return n^mask;
    }
};