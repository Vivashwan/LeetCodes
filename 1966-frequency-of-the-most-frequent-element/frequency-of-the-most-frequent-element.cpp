class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxim = 0;
        long currSum = 0;

        sort(nums.begin(), nums.end());

        int left=0, right=0;

        while(right<nums.size())
        {
            currSum+=nums[right];

            while(currSum+k < static_cast<long>(nums[right])*(right-left+1))
            {
                currSum-=nums[left];
                left++;
            }

            maxim = max(maxim, right-left+1);

            right++;
        }

        return maxim;
    }
};