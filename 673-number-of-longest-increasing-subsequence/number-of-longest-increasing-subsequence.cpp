class Solution {
public:
    pair<int, int>solveMem(vector<int>&nums, int n, int curr, int prev, vector<vector<pair<int, int>>>&dp) 
    {
        if(curr==n)
        { 
            return {0, 1};
        }

        if(dp[curr][prev+1].first!=-1)
        { 
            return dp[curr][prev+1];
        }

        int length=0, count=0;

        if(prev==-1 || nums[prev]<nums[curr])
        {
            pair<int, int>include = solveMem(nums, n, curr+1, curr, dp);

            int includeLength=1+include.first;

            if(includeLength>length)
            {
                length=includeLength, count=include.second;
            } 
            else if(includeLength==length)
            {
                count+=include.second;
            }
        }

        pair<int, int>exclude = solveMem(nums, n, curr+1, prev, dp);

        if(exclude.first>length)
        {
            length=exclude.first, count=exclude.second;
        } 
        else if(exclude.first==length)
        {
            count+=exclude.second;
        }

        dp[curr][prev+1] = {length, count};

        return dp[curr][prev+1];
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
    
        vector<vector<pair<int, int>>>dp(n+1, vector<pair<int, int>>(n+1, {-1, -1}));

        return solveMem(nums, n, 0, -1, dp).second;
    }
};