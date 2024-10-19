class Solution {
public:
    int minPairSum(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long maxim = INT_MIN;

        for(int i=0; i<n; i++)
        {
            maxim = max(maxim, (long long)nums[n-1-i]+nums[i]);
        }

        return (int)maxim;  
    }
};