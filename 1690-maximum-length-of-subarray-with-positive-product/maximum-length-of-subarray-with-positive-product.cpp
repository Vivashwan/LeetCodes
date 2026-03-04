class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos=0, neg=0, ans=0;

        for(auto it: nums)
        {
            if(it>0)
            {
                pos++;
                neg = (neg>0) ? neg+1: 0;
            }
            else if(it<0)
            {
                int newPos=(neg>0) ? neg+1: 0;
                int newNeg=pos+1;

                pos=newPos;
                neg=newNeg;
            }
            else
            {
                pos=0, neg=0;
            }

            ans=max(ans, pos);
        }

        return ans;
    }
};