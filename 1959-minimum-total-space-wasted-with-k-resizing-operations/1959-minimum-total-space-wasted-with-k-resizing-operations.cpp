class Solution {
private:
    int func(vector<int>& nums, int k, vector<vector<int>>&dp, int n, int ind)
    {
        if(ind>=n)
        {
            return 0;
        }

        if(k<0)
        {
            return 1e9;
        }

        if(dp[ind][k]!=-1)
        {
            return dp[ind][k];
        }

        int maxim = INT_MIN, sum = 0, ans = 1e9;

        for(int j=ind; j<n; j++)
        {
            maxim = max(maxim, nums[j]);

            sum+=nums[j];

            ans = min(ans, maxim*(j-ind+1)-sum + func(nums, k-1, dp, n, j+1));
        }

        return dp[ind][k] = ans;
    }
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));

        return func(nums, k, dp, n, 0);
    }
};