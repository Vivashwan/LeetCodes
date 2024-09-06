class Solution {
private:
    int maxSubarraySum(vector<int>& arr) 
    {
        int max_current = arr[0];
        int max_global = arr[0];

        for (int i = 1; i < arr.size(); ++i) 
        {
            max_current = max(arr[i], max_current + arr[i]);
            max_global = max(max_global, max_current);
        }

        return max_global;
    }

    int minSubarraySum(vector<int>& arr) 
    {
        int min_current = arr[0];
        int min_global = arr[0];

        for (int i = 1; i < arr.size(); ++i) 
        {
            min_current = min(arr[i], min_current + arr[i]);
            min_global = min(min_global, min_current);
        }

        return min_global;
    }
public:
    int maxAbsoluteSum(vector<int>& nums) {
        long long val1 = -1*(minSubarraySum(nums));
        long long val2 = maxSubarraySum(nums);

        return val1>val2? val1:val2;
    }
};