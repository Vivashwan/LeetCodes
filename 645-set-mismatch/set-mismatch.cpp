class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int xorForAll=0;

        for(auto it: nums)
        {
            xorForAll^=it;
        }

        for(int i=1; i<=n; i++)
        {
            xorForAll^=i;
        }

        int diffBit=xorForAll & -xorForAll;

        int x=0, y=0;

        for(auto it: nums)
        {
            if(it & diffBit)
            {
                x^=it;   
            }
            else y^=it;
        }

        for(int i=1; i<=n; i++)
        {
            if(i & diffBit)
            {
                x^=i;
            }
            else y^=i;
        }

        for(auto it: nums)
        {
            if(it==x)
            {
                return {x, y};
            }
        }

        return {y, x};
    }
};