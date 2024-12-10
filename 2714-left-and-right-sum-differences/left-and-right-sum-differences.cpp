class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>res;

        int leftSum=0, rightSum=0;

        for(auto it: nums)
        {
            leftSum+=it;
        }

        for(auto it: nums)
        {
            leftSum-=it;
            res.push_back(abs(leftSum-rightSum));
            rightSum+=it;
        }

        return res;
    }
};