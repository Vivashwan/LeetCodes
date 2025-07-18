class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();

        stack<int>st;

        for(int i=0; i<n; i++)
        {
            while(st.empty() || nums[st.top()]>nums[i])
            {
                st.push(i);
            }
        }

        int res=0;

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i])
            {
                res=max(res, i-st.top());
                st.pop();
            }
        }

        return res;
    }
};