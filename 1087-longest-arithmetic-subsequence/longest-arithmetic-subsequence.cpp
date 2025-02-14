class Solution {
private:
    int func(vector<int>&nums, int n, int ind, int diff, vector<vector<int>>&dp)
    {
        if(ind>=n)
        {
            return 0;
        }

        if(dp[ind][500+diff]!=-1)
        {
            return dp[ind][500+diff];
        }

        int res=0;

        for(int i=ind+1; i<n; i++)
        {
            if(nums[i]-nums[ind]==diff)
            {
                res=max(res, 1+func(nums, n, i, diff, dp));
            }
        }

        return dp[ind][500+diff] = res;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();

        int res=0;

        vector<vector<int>>dp(n+1, vector<int>(1001, -1));

        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                res=max(res, 2+func(nums, n, j, nums[j]-nums[i], dp));
            }
        }

        return res;
    }
};