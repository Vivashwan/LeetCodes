class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        int left = 0;

        for(int i=0; i<n; i++)
        {
            int right = (total-left)-nums[i];

            if(left==right)
            {
                return i;
            }

            left+=nums[i];
        }

        return -1;
    }
};