class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long mask=0;

        for(auto it: nums)
        {
            mask^=it;
        }

        long long diffBit=mask & -mask;

        int groupA=0, groupB=0;

        for(auto it: nums)
        {
            if(it & diffBit)
            {
                groupA^=it;
            }
            else groupB^=it;
        }

        return {groupA, groupB};
    }
};