class Solution {
private:
    int MOD=1e9+7;
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();

        vector<long long>prefixSum(n+1, 0);

        for(int i=0; i<n; i++)
        {
            prefixSum[i+1]=prefixSum[i]+nums[i];
        }

        vector<int>left(n, 0), right(n, 0);

        stack<int>st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }

            left[i]=st.empty() ? 0:st.top()+1;
            st.push(i);
        }

        while(!st.empty())
        {
            st.pop();
        }

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }

            right[i]=st.empty() ? n-1:st.top()-1;
            st.push(i);
        }

        long long res=0;

        for(int i=0; i<n; i++)
        {
            long long sum=prefixSum[right[i]+1]-prefixSum[left[i]];
            res=max(res, nums[i]*sum);
        }

        return res%MOD;
    }
};