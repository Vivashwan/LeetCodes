class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;

        int dups=0;

        for(int bit=0; bit<32; bit++)
        {
            int countNums=0;

            for(int i=1; i<=n; i++)
            {
                if(i & (1<<bit))
                {
                    countNums++;
                }
            }

            int countVals=0;

            for(auto it: nums)
            {
                if(it & (1<<bit))
                {
                    countVals++;
                }
            }

            if(countVals>countNums)
            {
                dups |=(1<<bit);
            }
        }

        return dups;
    }
};