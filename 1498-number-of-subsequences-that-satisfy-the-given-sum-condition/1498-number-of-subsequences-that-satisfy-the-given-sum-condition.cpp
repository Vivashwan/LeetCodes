class Solution {
private:
    int MOD = 1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int>power(n, 0);

        power[0] = 1;

        for(int i=1; i<n; i++)
        {
            power[i] = (power[i-1]*2)%MOD;
        }

        int low = 0, high = n-1;

        int res=0;

        while(low<=high)
        {
            if(nums[low]+nums[high]<=target)
            {
                int diff = high-low;
                res=(res%MOD+power[diff])%MOD;

                low++;
            }
            else high--;
        }

        return res;
    }
};