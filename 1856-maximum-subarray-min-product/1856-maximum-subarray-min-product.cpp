class Solution {
private:
    int MOD = 1e9+7;
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        long long res = 0;

        vector<long long>prefix(n+1, 0);

        for(int i=1; i<n+1; i++)
        {
            prefix[i] = prefix[i-1]+(long long)nums[i-1];
        }

        vector<int>left(n, 0), right(n, n);

        stack<int>st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                left[st.top()] = i+1;
                st.pop();
            }
            st.push(i);   
        }

        for(int i=0; i<n; i++)
        {
            long long rangeSum = prefix[right[i]]-prefix[left[i]];
            long long currProduct = rangeSum*nums[i];

            res = max(res, currProduct);
        }

        return res%MOD;
    }
};