class Solution {
private:
    bool func(vector<int>&nums, int n, int ind, int amount, vector<vector<int>>&dp)
    {
        for(int i=0; i<=n; i++)
        {
            dp[i][0]=1;
        }

        for(int ind=n-1; ind>=0; ind--)
        {
            for(int val=1; val<=amount; val++)
            {
                bool pick = false;

                if(val-nums[ind]>=0)
                {
                    pick = dp[ind+1][val-nums[ind]];
                }

                bool notPick = dp[ind+1][val];

                dp[ind][val] = pick || notPick;

            }
        }

        return dp[0][amount];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total%2!=0)
        {
            return false;
        }

        vector<vector<int>>dp(n+1, vector<int>((total/2)+1, 0));

        return func(nums, n, 0, total/2, dp);
    }
};