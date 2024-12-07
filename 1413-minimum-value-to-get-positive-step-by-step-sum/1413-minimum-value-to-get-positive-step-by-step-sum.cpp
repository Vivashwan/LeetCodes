class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0, mini = INT_MAX;

        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];

            mini = min(mini, sum);
        }

        return max(1, 1-mini);
    }
};