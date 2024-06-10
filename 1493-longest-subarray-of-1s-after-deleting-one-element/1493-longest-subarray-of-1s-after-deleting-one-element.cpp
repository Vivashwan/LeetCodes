class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int left=0, right=0, res=0, count=0;

        while(right<n)
        {
            if(nums[right]==0)
            {
                count++;
            }

            while(count>1)
            {
                if(nums[left]==0)
                {
                    count--;
                }
                left++;
            }

            res = max(res, right-left);
            right++;
        }

        return res;
    }
};