class Solution {
private:
    int func(vector<int>&nums, int n, int start, int end, int turn)
    {
        if(start==n || end==-1)
        {
            return 0;
        }

        if(start>end)
        {
            return 0;
        }

        if(turn==0)
        {
            return max(nums[start]+func(nums, n, start+1, end, 1), nums[end]+func(nums, n, start, end-1, 1));
        }
        else
        {
            return min(-nums[start]+func(nums, n, start+1, end, 0), -nums[end]+func(nums, n, start, end-1, 0));
        }
    }
    
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int val = func(nums, n, 0, n-1, 0);

        return val>=0;
    }
};