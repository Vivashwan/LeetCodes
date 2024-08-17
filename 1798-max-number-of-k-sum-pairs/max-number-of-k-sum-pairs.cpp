class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0, n = nums.size();

        for(int i = 0; i < n; i++) 
        {
            int comp = k - nums[i];
            if(mp[comp] > 0) 
            {
                count++;
                mp[comp]--;
            } 
            else 
            {
                mp[nums[i]]++;
            }
        }

        mp.clear();

        return count;
    }
};
