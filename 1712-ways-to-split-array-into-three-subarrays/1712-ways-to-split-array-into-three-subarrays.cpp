class Solution {
private:
    int MOD=1e9+7;
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();

        vector<int>prefix(n+1, 0);

        for(int i=0; i<n; i++)
        {
            prefix[i+1]=nums[i]+prefix[i];
        }

        int low=1, high=1;
        long long res=0;

        for(int i=1; i<=n-2; i++)
        {
            long long leftSubarray=prefix[i];

            low=max(low, i+1);

            while(low<n && prefix[low]<2*leftSubarray)
            {
                low++;
            }

            high=max(high, low);

            while(high<n && prefix[high]<=(prefix[n]+leftSubarray)/2)
            {
                high++;
            }

            if(low<=high-1)
            {
                res=(res+(high-1-(low)+1))%MOD;
            }
        }

        return (int)res;
    }
};