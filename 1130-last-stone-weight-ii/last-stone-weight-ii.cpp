class Solution {
private:
    int func(vector<int>&stones, int n, int target, int ind, vector<vector<int>>&dp)
    {
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int val=1; val<=target; val++)
            {
                int notPick=0+dp[ind+1][val];

                int pick=0;

                if(stones[ind]<=val)
                {
                    pick=stones[ind]+dp[ind+1][val-stones[ind]];
                }

                dp[ind][val] = max(pick, notPick);
            }
        }

        return dp[0][target];
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int sum=accumulate(stones.begin(), stones.end(), 0);

        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));

        return sum-2*func(stones, n, sum/2, 0, dp);
    }
};