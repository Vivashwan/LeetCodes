class Solution {
private:
    bool func(vector<int>&nums, int threshold, int mid, int n)
    {
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=(nums[i]-1)/mid+1;
        }

        return sum<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();

        int low=1, high=*max_element(nums.begin(), nums.end());
        int res=INT_MAX;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(func(nums, threshold, mid, n))
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        return res;
    }
};