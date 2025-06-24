class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
        {
            return nums[0];
        }

        int low=0, high=n-1;

        while(low<high)
        {
            int mid=(low+high)>>1;

            if(mid>0 && nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }

            if(nums[mid]>nums[high])
            {
                low=mid+1;
            }
            else if(nums[mid]<nums[high])
            {
                high=mid;
            }
            else high--;
        }

        return nums[low];
    }
};