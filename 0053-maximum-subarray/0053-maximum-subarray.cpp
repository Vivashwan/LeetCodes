class Solution {
public:
    int maxSubArray(vector<int>& nums) {

    long long maxim = LONG_MIN;
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];

        if (sum > maxim)
        {
            maxim = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxim;

    }
};