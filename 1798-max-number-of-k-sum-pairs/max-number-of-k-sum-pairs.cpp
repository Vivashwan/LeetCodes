class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) 
        {
            int complement = k - nums[i];
            if(mp[complement] > 0) 
            {
                count++;
                mp[complement]--;
            } 
            else 
            {
                mp[nums[i]]++;
            }
        }

        return count;
    }
};
