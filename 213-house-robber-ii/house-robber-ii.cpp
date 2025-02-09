class Solution {
private:
    int robing(int index,vector<int> &nums, vector<int>&dp)
    {
        if(index<0)
        {
            return 0;
        }

        if(index==0)
        {
            return nums[0];
        }

        if(dp[index]!=-1)
        {
            return dp[index];
        }

        int pick=nums[index]+robing(index-2,nums, dp);
        int notPick=0+robing(index-1,nums, dp);

        return dp[index] = max(pick,notPick);
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        {
            return nums[0];
        }

        vector<int>temp1,temp2;

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

        vector<int>dp1(n1, -1), dp2(n2, -1);

        int ans1=robing(n1-1,temp1, dp1);
        int ans2=robing(n2-1,temp2, dp2);

        return max(ans1,ans2);
    }
};