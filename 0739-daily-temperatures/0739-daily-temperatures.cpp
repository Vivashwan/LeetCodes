class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();

        stack<int>st;

        vector<int>res(n, 0);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && temperatures[i]>temperatures[st.top()])
            {
                res[st.top()]=i-st.top();
                st.pop();
            }

            st.push(i);
        }

        return res;
    }
};