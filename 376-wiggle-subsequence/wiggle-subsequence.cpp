class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        if(n==1) 
        {
            return 1;
        }

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));

        for(int ind=n-1; ind>=0; ind--) 
        {
            for(int prev=ind-1; prev>=-1; prev--) 
            {  
                for(int positive=0; positive<2; positive++) 
                {
                    int pick=0;

                    if((positive && (prev==-1 || nums[ind]>nums[prev])) || 
                        (!positive && (prev==-1 || nums[ind]<nums[prev]))) {
                        pick = 1 + dp[ind+1][ind+1][!positive]; 
                    }

                    int notPick = (ind+1<n) ? dp[ind+1][prev+1][positive]:0;
                    
                    dp[ind][prev+1][positive] = max(pick, notPick);
                }
            }
        }
        
        return max(dp[0][0][0], dp[0][0][1]);
    }
};
