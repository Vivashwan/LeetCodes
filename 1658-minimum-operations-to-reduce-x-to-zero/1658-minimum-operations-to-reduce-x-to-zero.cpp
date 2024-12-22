class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        int req = total-x;

        if(req==0)
        {
            return n;
        }

        int left = 0, maxi = 0, currSum = 0;

        for(int right=0; right<n; right++)
        {
            currSum+=nums[right];

            while(left<=right && currSum>req)
            {
                currSum-=nums[left];
                left++;
            }

            if(currSum==req)
            {
                maxi = max(maxi, right-left+1);
            }
        }

        return maxi ? n-maxi: -1;
    }
};