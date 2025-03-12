class Solution {
private:
    int func(vector<int>&nums1, vector<int>&nums2, int ind1, int ind2, vector<vector<int>>& dp) 
    {
        if(ind1>=nums1.size() || ind2>=nums2.size()) 
        {    
            return 0;
        } 

        if(dp[ind1][ind2]!=-1) 
        {    
            return dp[ind1][ind2];
        }

        int res=0;

        if(nums1[ind1]==nums2[ind2]) 
        {
            res = 1+func(nums1, nums2, ind1+1, ind2+1, dp);
        }

        return dp[ind1][ind2]=res;
    }

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();

        vector<vector<int>>dp(n, vector<int>(m, -1)); 

        int maxLen=0;

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                maxLen = max(maxLen, func(nums1, nums2, i, j, dp));
            }
        }

        return maxLen;
    }
};
