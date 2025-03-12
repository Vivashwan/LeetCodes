class Solution {
private:
    int func(vector<int>&arr, unordered_map<int, int>&mp, int i, int j, vector<vector<int>>&dp, int n)
    {
        if(i>=n || j>=n)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int res=0;

        int next=arr[i]+arr[j];

        if(mp.find(next)!=mp.end())
        {
            int nextJumpIndex=mp[next];
            res=1+func(arr, mp, j, nextJumpIndex, dp, n);
        }

        return dp[i][j]=res;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int>mp;

        for(int i=0; i<n; i++)
        {
            mp[arr[i]]=i;
        }

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        int res=0;

        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                res=max(res, 2+func(arr, mp, i, j, dp, n));
            }
        }

        return res>2?res:0;
    }
};