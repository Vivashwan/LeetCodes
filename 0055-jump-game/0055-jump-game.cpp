class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        for(int i=0; i<n; i++)
        {
            if(i>ind)
            {
                return false;
            }

            ind = max(i+nums[i], ind);
        }


        return true;
    }
};