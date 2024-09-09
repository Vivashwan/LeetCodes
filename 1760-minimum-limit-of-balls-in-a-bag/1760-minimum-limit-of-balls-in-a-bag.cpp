class Solution {
private:
    bool isPossible(vector<int>&nums, int mid, int maxOps)
    {
        int count = 0;

        for(auto it: nums)
        {
            if(it%mid==0)
            {
                count+=(it/mid)-1;
            }
            else count+=(it/mid);

            if(count>maxOps)
            {
                return false;
            }
        }

        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int start = 1, end = INT_MIN;

        for(auto it: nums)
        {
            end = max(it, end);
        }

        int res = 0;

        while(start<=end)
        {
            int mid = start+(end-start)/2;

            if(isPossible(nums, mid, maxOperations))
            {
                res = mid;
                end = mid-1;
            }
            else start = mid+1;
        }

        return res;
    }
};