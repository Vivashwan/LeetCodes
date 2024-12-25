class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        vector<long long>prefix(n, 0);

        prefix[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            prefix[i]+=prefix[i-1]+nums[i];
        }   

        int res = 0, mini = INT_MAX;

        for(int i=0; i<n; i++)
        {
            long long leftAvg = prefix[i] / (i + 1),
            rightAvg = (i == n - 1) ? 0 : (prefix[n - 1] - prefix[i]) / (n - i - 1);

            long long avgDiff = abs(leftAvg - rightAvg);

            if (avgDiff < mini) {
                mini = avgDiff;
                res = i;
            }
        }

        return res;
    }
};