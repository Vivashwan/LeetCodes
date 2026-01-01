class Solution {
public:
    int minOperations(vector<int>& nums) {
        int addOneOps=0, highestSetBit=0;

        for(int i=0; i<=30; i++)
        {
            for(auto it: nums)
            {
                if((it&(1<<i)))
                {
                    addOneOps++;
                    highestSetBit=i;
                }
            }
        }

        return addOneOps+highestSetBit;
    }
};