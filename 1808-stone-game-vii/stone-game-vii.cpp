class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>>dp(n, vector<int>(n, 0)); 
        vector<int>prefixSum(n+1, 0);

        for(int i=0; i<n; i++)
        {
            prefixSum[i+1] = prefixSum[i]+stones[i];
        }

        for(int len=2; len<=n; len++) 
        {
            for(int left=0; left+len-1<n; left++) 
            {
                int right=left+len-1;

                int total=prefixSum[right+1]-prefixSum[left]; 
                
                int scoreRemoveLeft=total-stones[left]-dp[left+1][right];
                
                int scoreRemoveRight=total-stones[right]-dp[left][right-1];

                dp[left][right] = max(scoreRemoveLeft, scoreRemoveRight);
            }
        }

        return dp[0][n-1];
    }
};