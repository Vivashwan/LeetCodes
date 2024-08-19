class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum=0, n=nums.size();

        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }

        vector<int>res;
        int leftSum=0, rightSum=0;

        for(int i=0; i<n; i++)
        {
            leftSum+=nums[i];
            rightSum=sum-leftSum;

            res.push_back(nums[i]*(i+1)-leftSum+rightSum-nums[i]*(n-1-i));
        }

        return res;
    }
};