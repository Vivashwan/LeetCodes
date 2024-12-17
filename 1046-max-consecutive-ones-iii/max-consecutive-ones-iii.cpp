class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(), count=0, left=0, maxim = INT_MIN;

        for(int right=0; right<n; right++)
        {
            if(nums[right]==0)
            {
                count++;
            }

            while(count>k)
            {
                if(nums[left]==0)
                {
                    count--;
                }
                left++;
            }

            maxim = max(maxim, right-left+1);
        }

        return maxim;
    }
};