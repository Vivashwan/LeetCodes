class Solution {
private:
    int func(vector<int>&nums, int ind, int diff, int n, vector<vector<int>>&dp)
    {
        if(ind==n)
        {
            return 0;
        }

        if(dp[ind][500+diff]!=-1)
        {
            return dp[ind][500+diff];
        }

        int ans=0;

        for(int i=ind+1; i<n; i++)
        {
            if(nums[i]-nums[ind]==diff)
            {
                int count=1+func(nums, i, diff, n, dp);
                ans=max(ans, count);
            }
        }

        return dp[ind][500+diff]=ans;
    }

public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans=1, n=nums.size();

        vector<vector<int>>dp(n+1, vector<int>(1001, -1));

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int temp=2+func(nums, j, nums[j]-nums[i], n, dp);
                ans=max(ans, temp);
            }
        }

        return ans;
    }
};