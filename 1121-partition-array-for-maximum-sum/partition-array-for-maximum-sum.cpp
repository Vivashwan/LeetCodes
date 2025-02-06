class Solution {
private:
    int func(vector<int>&arr, int n, int k, vector<int>&dp)
    {
        for(int ind=n-1; ind>=0; ind--)
        {
            int maxi=INT_MIN, len=0, maxSum=INT_MIN;

            for(int i=ind; i<min(ind+k, n); i++)
            {
                len++;

                maxi = max(maxi, arr[i]);

                int sum = len*maxi + dp[i+1];

                maxSum = max(maxSum, sum);
            }

            dp[ind] = maxSum;
        }

        return dp[0];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int>dp(n+1, 0);

        return func(arr, n, k, dp);
    }
};