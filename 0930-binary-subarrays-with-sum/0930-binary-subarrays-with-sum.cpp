class Solution {
private:
    int atMost(vector<int>&nums, int goal)
    {
        int n=nums.size();
        int sum=0, left=0, right=0, count=0;

        while(right<n)
        {
            sum+=nums[right];

            while(left<=right && sum>goal)
            {
                sum-=nums[left];
                left++;
            }

            count+=(right-left+1);
            right++; 
        }
        
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal)-atMost(nums, goal-1);
    }
};