class Solution {
private:
    long long getSum(vector<int>&nums, int n, bool isMax)
    {
        stack<int>st;

        long long res=0;

        for(int i=0; i<=n; i++)
        {
            while(!st.empty() && (i==n || (isMax ? nums[st.top()]<nums[i] : nums[st.top()]>nums[i])))
            {
                int mid=st.top();
                st.pop();

                int left=st.empty() ? -1:st.top();

                int right=i;

                long long count=(mid-left)*(1LL)*(right-mid);
                
                // nums[mid] is the maximum in all subarrays that start anywhere from left+1 to mid, and end anywhere from mid to right-1`

                // This counts all subarrays [start, end] such that:

                // start ∈ [left + 1, mid]

                // end ∈ [mid, right - 1]

                // So that nums[mid] is the max/min in those subarrays.

                res+=nums[mid]*count;
            }

            st.push(i);
        }

        return res;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();

        return getSum(nums, n, true)-getSum(nums, n, false);
    }
};