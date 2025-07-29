class Solution {
private:
    void func(int ind, int n, vector<int>&nums, int target, int& count, int sum)
    {
        if(ind==n && sum==target)
        {
            count++;
            return;
        }
        else if(ind==n)
        {
            return;
        }

        sum+=nums[ind];

        func(ind+1, n, nums, target, count, sum);
        sum-=2*nums[ind];
        func(ind+1, n, nums, target, count, sum);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        int count=0, sum=0;

        func(0, n, nums, target, count, sum);

        return count;
    }
};