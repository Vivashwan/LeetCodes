class Solution {
private:
    int atMost(vector<int>&nums, int goal)
    {
        int n=nums.size(), count=0, sum=0, left=0;

        for(int right=0; right<n; right++)
        {
            sum+=nums[right];

            while(left<=right && sum>goal)
            {
                sum-=nums[left];
                left++;
            }

            count+=(right-left+1); 
        }

        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal)-atMost(nums, goal-1);
    }
};