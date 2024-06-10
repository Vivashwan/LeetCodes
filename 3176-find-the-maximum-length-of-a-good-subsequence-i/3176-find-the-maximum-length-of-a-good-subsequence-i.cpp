class Solution {
    private:
    int n;
    vector<vector<vector<int>>>dp;
    int func(vector<int>&nums,int k,int id,int prev){
         if(id >= n) return 0;
        if(dp[id][k][prev+1]!=-1) return dp[id][k][prev+1];
        int take = 0,nottake = 0;
        if(prev == -1){
            take = 1+func(nums,k,id+1,id);
            nottake = func(nums,k,id+1,prev);
        }
        else{
            if(nums[prev] != nums[id]){
              if(k-1>=0) take = 1+func(nums,k-1,id+1,id);
                nottake = func(nums,k,id+1,prev);
            }
            else{
                take = 1 + func(nums,k,id+1,id);
                nottake = func(nums,k,id+1,prev);
            }
        }
        return dp[id][k][prev+1] = max(take,nottake);
        
    }
public:
    int maximumLength(vector<int>& nums, int k) {
         n = nums.size();
        if(k==0){
            unordered_map<int,int> mp;
            int maxi = 0;
            for(auto & it: nums){
                mp[it]++;
                maxi = max(maxi,mp[it]);
            }
            return maxi;
            
        
        }
        dp.resize(n+1,vector<vector<int>>(k+1,vector<int>(n+2,-1)));
        return func(nums,k,0,-1);
    }
};