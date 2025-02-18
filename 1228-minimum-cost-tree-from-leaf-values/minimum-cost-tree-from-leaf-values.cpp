class Solution {
private:
    int maxNonLeaf(vector<int>&arr, int start, int end)
    {
        int maxim = 0;

        for(int i=start; i<=end; i++)
        {
            maxim = max(maxim, arr[i]);
        }

        return maxim;
    }

    int func(vector<int>&arr, int n, int start, int end, vector<vector<int>>&dp)
    {
        if(start==end)
        {
            return 0;
        }   

        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }

        int res=INT_MAX;

        for(int i=start; i<end; i++)
        {
            int leftMax=maxNonLeaf(arr, start, i);
            int rightMax=maxNonLeaf(arr, i+1, end);

            res=min(res, func(arr, n, start, i, dp)+func(arr, n, i+1, end, dp)+leftMax*rightMax);
        }

        return dp[start][end] = res;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return func(arr, n, 0, n-1, dp);
    }
};