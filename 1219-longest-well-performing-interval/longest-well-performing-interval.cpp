class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        vector<int>prefix(n+1, 0);

        for(int i=0; i<n; i++)
        {
            prefix[i+1]=prefix[i]+(hours[i]>8?1 : -1);
        }

        stack<int>st;

        for(int i=0; i<=n; i++)
        {
            if(st.empty() || prefix[i]<prefix[st.top()])
            {
                st.push(i);
            }
        }

        int res=0;

        for(int i=n; i>=0; i--) 
        {
            while(!st.empty() && prefix[i]>prefix[st.top()])
            {
                res=max(res, i-st.top());
                st.pop();
            }
        }

        return res;
    }
};
