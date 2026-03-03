class Solution {
private:
    bool canMake(vector<int>&nums, int n, long long mid)
    {
        long long total=0;

        for(int i=0; i<n; i++)
        {
            total+=nums[i];

            if(total>mid*(i+1))
            {
                return false;
            }
        }

        return true;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();

        int low=0, high=*max_element(nums.begin(), nums.end());

        int res=high;

        while(low<=high)
        {
            long long mid=low+(high-low)/2;

            if(canMake(nums, n, mid))
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