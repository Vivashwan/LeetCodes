class Solution {
public:
    char findKthBit(int n, int k) {
        char res;
        int invertCount=0;

        while(n>1)
        {
            int len=(1<<n)-1;

            int mid=(len+1)/2;

            if(k==mid)
            {
                break;
            }

            if(k>mid)
            {
                k=len-k+1;
                invertCount^=1;
            }

            n--;
        }

        res = (k==1) ? '0': '1';

        if(invertCount)
        {
            res = (res=='0') ? '1' : '0';
        }

        return res;
    }
};