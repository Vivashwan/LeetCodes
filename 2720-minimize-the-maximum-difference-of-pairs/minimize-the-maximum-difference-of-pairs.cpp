class Solution {
bool canFormPairs(vector<int>&nums, int n, int p, int mid)
{
    int pairs=0, i=0;

    while(i<n-1)
    {
        if(nums[i+1]-nums[i]<=mid)
        {
            pairs++;
            i+=2;
        }
        else i++;
    }
    
    return pairs>=p;
}
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int n=nums.size();

        int left=0, right=nums[n-1]-nums[0];
        int res=right;

        while(left<=right)
        {   
            int mid=left+(right-left)/2;

            if(canFormPairs(nums, n, p, mid))
            {
                res=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }

        return res;
    }
};