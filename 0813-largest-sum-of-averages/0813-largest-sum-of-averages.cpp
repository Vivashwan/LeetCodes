class Solution {
private:
    double func(vector<int>&nums, int n, int k, int left, vector<vector<double>>&dp)
    {
        if(left>=n)
        {
            return 0.0;
        }

        if(k==0)
        {
            return INT_MIN/2;
        }        

        if(dp[left][k]!=-1.0)
        {
            return dp[left][k];
        }

        double res=0.0, sum=0.0;

        for(int i=left; i<n; i++)
        {
            sum+=nums[i];
            res=max(res, sum/(i-left+1)+func(nums, n, k-1, i+1, dp));
        }

        return dp[left][k] = res;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<double>>dp(110, vector<double>(110, -1.0));
        return func(nums, n, k, 0, dp);
    }
};