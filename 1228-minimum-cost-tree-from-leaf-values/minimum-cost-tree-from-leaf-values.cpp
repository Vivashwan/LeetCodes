class Solution {
private:
    int maxNonLeaf(vector<int>&arr, int start, int end) 
    {
        int maxim=0;
        for (int i=start; i<=end; i++) 
        {
            maxim=max(maxim, arr[i]);
        }

        return maxim;
    }

    int func(vector<int>&arr, int n, vector<vector<int>>&dp) 
    {
        for(int length=2; length<=n; length++) 
        { 
            for(int start=0; start<=n-length; start++) 
            {
                int end=start+length-1;

                dp[start][end]=INT_MAX;

                for(int i=start; i<end; i++) 
                { 
                    int leftMax=maxNonLeaf(arr, start, i);
                    int rightMax=maxNonLeaf(arr, i+1, end);

                    dp[start][end] = min(dp[start][end], dp[start][i]+dp[i+1][end]+leftMax*rightMax);
                }
            }
        }

        return dp[0][n-1];
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        return func(arr, n, dp);
    }
};
