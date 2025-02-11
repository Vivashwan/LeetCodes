class Solution {
private:
    int func(vector<int>&nums, int n, int target, int ind)
    {
        if(ind==n)
        {
            if(target==0)
            {
                return 1;
            }
            else return 0;
        }

        int pos = func(nums, n, target-nums[ind], ind+1);
        int neg = func(nums, n, target+nums[ind], ind+1);

        return pos+neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return func(nums, n, target, 0);
    }
};