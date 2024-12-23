class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0, right = 0, maxim = INT_MIN;

        long sum = 0;

        while(right<n)
        {
            sum+=nums[right];

            while(sum+k<static_cast<long>(nums[right])*(right-left+1))
            {
                sum-=nums[left];
                left++;
            }

            maxim = max(maxim, right-left+1);

            right++;
        }

        return maxim;
    }
};