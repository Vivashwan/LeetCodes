class Solution {
private:
    int MOD=1e9+7;
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n, 0);

        prefix[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }

        int count = 0;

        for(int i=0; i<n-2; i++)
        {
            int j = lower_bound(prefix.begin()+i+1, prefix.end()-1, 2*prefix[i])-prefix.begin();
            int k = upper_bound(prefix.begin()+i+1, prefix.end()-1, (prefix[i]+prefix.back())/2)-prefix.begin()-1;

            if(j<=k)
            {
                count+=(k-j+1);
                count%=MOD;
            }
        }

        return count%MOD;
    }
};