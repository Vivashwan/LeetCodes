class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, int>mp;

        for(int i=0; i<n; i++) 
        {
            mp[arr[i]]=i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2)); 

        int res=0;

        for(int j=1; j<n; j++) 
        {
            for(int i=0; i<j; i++)
            {
                int expectedPrev=arr[j]-arr[i];

                if(expectedPrev<arr[i] && mp.find(expectedPrev)!=mp.end()) 
                {
                    int k = mp[expectedPrev];
                    dp[i][j] = dp[k][i] + 1;
                    res = max(res, dp[i][j]); 
                }
            }
        }
        return res>2 ? res:0;
    }
};