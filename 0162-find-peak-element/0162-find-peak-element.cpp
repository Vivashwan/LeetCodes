class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0, high=nums.size()-1;

        while(low<=high) 
        {
            int mid=low+(high-low)/2;

            bool leftOK=(mid==0) || (nums[mid]>nums[mid-1]);
            bool rightOK=(mid==nums.size()-1) || (nums[mid]>nums[mid+1]);

            if(leftOK && rightOK) 
            {
                return mid; 
            } 
            else if(!leftOK)
            {
                high=mid-1;
            } 
            else
            {
                low=mid+1;
            }
        }

        return -1;
    }
};