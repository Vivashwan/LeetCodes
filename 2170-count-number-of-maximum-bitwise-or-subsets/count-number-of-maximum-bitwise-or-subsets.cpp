class Solution {
private:
    int maxi=0;
    unordered_map<int, int>mp;

    void func(vector<int>&nums, int n, int ind, int temp)
    {
        if(ind==n)
        {
            maxi=max(maxi, temp);

            mp[temp]++;
        
            return;
        }

        func(nums, n, ind+1, temp);

        temp|=nums[ind];
        func(nums, n, ind+1, temp);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();

        func(nums, n, 0, 0);

        int count=0;

        for(auto it: mp)
        {
            count=max(count, it.second);
        }

        return count;
    }
};