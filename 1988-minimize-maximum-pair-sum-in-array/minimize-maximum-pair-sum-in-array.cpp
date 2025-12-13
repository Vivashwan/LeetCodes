class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(), nums.end());

        int left=0, right=n-1;

        int maxim=INT_MIN;

        while(left<right)
        {
            maxim=max(maxim, nums[left]+nums[right]);
            left++, right--;
        }

        return maxim;
    }
};