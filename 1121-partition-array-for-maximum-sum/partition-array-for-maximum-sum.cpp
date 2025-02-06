class Solution {
private:
    int func(vector<int>&arr, int n, int k, int ind, vector<int>&dp)
    {
        if(ind==n)
        {
            return 0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        int maxi=INT_MIN, len=0, maxSum=INT_MIN;

        for(int i=ind; i<min(ind+k, n); i++)
        {
            len++;

            maxi = max(maxi, arr[i]);

            int sum = len*maxi + func(arr, n, k, i+1, dp);

            maxSum = max(maxSum, sum);
        }

        return dp[ind] = maxSum;

    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int>dp(n+1, -1);

        return func(arr, n, k, 0, dp);
    }
};