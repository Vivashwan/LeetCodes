class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0, maxSum=nums[0], minSum=nums[0], currMax=0, currMin=0;

        for(auto it: nums)
        {
            currMax=max(currMax+it, it);
            maxSum=max(maxSum, currMax);

            currMin=min(currMin+it, it);
            minSum=min(minSum, currMin);

            totalSum+=it;
        }

        if(maxSum<0)
        {
            return maxSum;
        }

        return max(maxSum, totalSum-minSum);
    }
};