class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        int xorForAll=0;

        for(int i=0; i<=n; i++)
        {
            xorForAll^=i;
        }

        int xorForNums=0;

        for(auto it: nums)
        {
            xorForNums^=it;
        }

        return xorForNums^xorForAll;
    }
};