class Solution {
private:
    int func(vector<int>&stones, int n, int target, int ind, vector<vector<int>>&dp)
    {
        if(target==0 || ind>=n)
        {
            return 0;
        }

        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }

        int notPick=0+func(stones, n, target, ind+1, dp);

        int pick=0;

        if(stones[ind]<=target)
        {
            pick=stones[ind]+func(stones, n, target-stones[ind], ind+1, dp);
        }

        return dp[ind][target] = max(pick, notPick);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int sum=accumulate(stones.begin(), stones.end(), 0);

        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));

        return sum-2*func(stones, n, sum/2, 0, dp);
    }
};