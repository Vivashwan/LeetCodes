class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();

        int res=0;

        stack<int>st;

        st.push(INT_MAX);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && st.top()<=arr[i])
            {
                int mid=st.top();
                st.pop();

                res+=min(st.top(), arr[i])*mid;
            }

            st.push(arr[i]);
        }

        while(st.size()>2)
        {
            int mid=st.top();
            st.pop();

            res+=mid*st.top();
        }

        return res;
    }
};