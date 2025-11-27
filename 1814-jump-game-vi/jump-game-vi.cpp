class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>dp(n, 0);

        deque<int>d;

        d.push_front(0);
        dp[0]=nums[0];

        for(int i=1; i<n; i++)
        {
            if(!d.empty() && d.front()<i-k)
            {
                d.pop_front();
            }

            dp[i]=nums[i]+dp[d.front()];

            while(!d.empty() && dp[i]>=dp[d.back()])
            {
                d.pop_back();
            }

            d.push_back(i);
        }

        return dp[n-1];
    }
};