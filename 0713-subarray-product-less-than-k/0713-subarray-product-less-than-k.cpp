class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int prod = 1, count = 0, i = 0;

        for(int j=0; j<n; j++)
        {
            prod*=nums[j];

            while(i<=j && prod>=k)
            {
                prod/=nums[i];
                i++;
            }

            count += j-i+1;
        }

        return count;
    }
};