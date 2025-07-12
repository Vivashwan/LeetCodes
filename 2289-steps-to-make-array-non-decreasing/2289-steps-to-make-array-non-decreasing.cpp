class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>>st;
        int res=0;

        for(int num: nums)
        {
            int maxSteps=0;

            while(!st.empty() && st.top().first<=num)
            {
                maxSteps=max(maxSteps, st.top().second);
                st.pop();
            }

            int steps=(st.empty() ? 0 : maxSteps+1);
            res=max(res, steps);
            
            st.push({num, steps});
        }

        return res;
    }
};