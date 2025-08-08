class Solution {
private:
    double func(vector<int>&nums, int n, int left, int k, vector<vector<double>>&dp)
    {
        if(left>=n)
        {
            return 0.0;
        }

        if(dp[left][k]!=-1)
        {
            return dp[left][k];
        }

        if(k==0)
        {
            return INT_MIN/2;
        }

        double sum=0.0, res=0.0; 

        for(int i=left; i<n; i++)
        {
            sum+=nums[i];

            res=max(res, sum/(i-left+1)+func(nums, n, i+1, k-1, dp));
        }

        return dp[left][k]=res;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();

        vector<vector<double>>dp(n, vector<double>(k+1, -1));

        return func(nums, n, 0, k, dp);
    }
};