class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        long long total = 0, res = 0;

        for(int i=0; i<n; i++)
        {
            total += nums[i];
            long long val=ceil((total)/(i+1.0));
            res = max(res, val);
        }

        return res;
    }
};