class Solution {
private:
    int func(vector<int>&nums, int n, int curr, int prev, int diff)
    {
        if(curr>=n || nums[curr]-nums[prev]!=diff)
        {
            return 0;
        }

        return 1+func(nums, n, curr+1, curr, diff);
    }

public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();

        if(n<3)
        {
            return 0;
        }

        int count=0;

        for(int i=0; i<n-2; i++)
        {
            int diff=nums[i+1]-nums[i];
            count+=func(nums, n, i+2, i+1, diff);
        }

        return count;
    }
};