class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int left=0, right=0, maxi=0;
        long long sum=0;

        while(right<n)
        {
            sum+=nums[right];

            while(sum+k<(long long)nums[right]*(right-left+1))
            {
                sum-=nums[left];
                left++;
            }

            maxi=max(maxi, right-left+1);
            right++;
        }

        return maxi;
    }
};