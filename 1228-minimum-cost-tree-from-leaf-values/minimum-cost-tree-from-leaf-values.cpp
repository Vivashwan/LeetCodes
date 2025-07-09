class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res=0;
        stack<int>st;

        st.push(INT_MAX);

        for(auto it: arr)
        {
            while(!st.empty() && st.top()<=it)
            {
                int mid=st.top();
                st.pop();
                res+=mid*min(st.top(), it);
            }
            
            st.push(it);
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