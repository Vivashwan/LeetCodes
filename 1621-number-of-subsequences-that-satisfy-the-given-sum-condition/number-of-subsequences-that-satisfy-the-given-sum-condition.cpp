class Solution {
private:
    int MOD=1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(), nums.end());

        vector<int>power(n, 1);

        int count=0;

        for(int i=1; i<n; i++)
        {
            power[i]=(2*power[i-1])%MOD;
        }

        int low=0, high=n-1;

        while(low<=high)
        {
            if(nums[low]+nums[high]<=target)
            {
                count=(count+power[high-low])%MOD;
                low++;
            }
            else high--;
        }

        return count;
    }
};