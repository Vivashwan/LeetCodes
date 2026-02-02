class Solution {
public:
    int brokenCalc(int val, int target) {
        int res=0;

        while(target>val)
        {
            res++;

            if(target%2==0)
            {
                target/=2;
            }
            else target+=1;
        }

        res+=val-target;

        return res;
    }
};