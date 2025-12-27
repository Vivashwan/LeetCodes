class Solution {
private:
    bool isPossible(vector<int>&nums, int k, int mid) 
    {
        int count=0;
        bool prevTaken=false;

        for(int i=0; i<nums.size(); i++) 
        {
            if(!prevTaken && nums[i]<=mid) 
            {
                count++;
                prevTaken=true;
                if(count>=k)
                { 
                    return true;
                }
            } 
            else 
            {
                prevTaken=false;
            }
        }

        return false;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();

        int low=*min_element(nums.begin(), nums.end());
        int high=*max_element(nums.begin(), nums.end());

        int res=0;

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(isPossible(nums, k, mid))
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