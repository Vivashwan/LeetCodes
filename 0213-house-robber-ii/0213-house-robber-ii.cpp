class Solution {
private:
    int robing(int n,vector<int> &nums, vector<int>&dp)
    {
        dp[0]=nums[0];

        for(int i=1; i<n; i++)
        {
            int pick=nums[i];

            if(i>1)
            {
                pick+=dp[i-2];
            }
            
            int notPick=dp[i-1];

            dp[i] = max(pick,notPick);
        }

        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        {
            return nums[0];
        }

        vector<int>temp1, temp2;

        for(int i=0;i<n;i++)
        {
            if(i!=0)    
            {
                temp1.push_back(nums[i]);
            }

            if(i!=nums.size()-1)
            {
                temp2.push_back(nums[i]);
            }
        }

        int n1=temp1.size(), n2=temp2.size();

        vector<int>dp1(n1+1, 0), dp2(n2+1, 0);

        int ans1=robing(n1, temp1, dp1);
        int ans2=robing(n2, temp2, dp2);

        return max(ans1,ans2);
    }
};