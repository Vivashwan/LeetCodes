class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int>dp(n, 1), child(n, -1);

        int index=0;

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(1+dp[j]>dp[i])
                    {
                        dp[i]=1+dp[j];

                        child[i]=j;
                    }
                }
            }

            if(dp[i]>dp[index])
            {
                index=i;
            }
        }

        vector<int>res;

        while(index!=-1)
        {
            res.push_back(nums[index]);
            index=child[index];
        }

        return res;
    }
};