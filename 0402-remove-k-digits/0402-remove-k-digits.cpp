class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        for(auto it: num)
        {
            while(!st.empty() && it<st.top() && k>0)
            {
                st.pop();
                k--;
            }

            st.push(it);
        }

        while(k>0 && !st.empty())
        {
            st.pop();
            k--;
        }

        string res="";

        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i=0; 

        while(i<res.length() && res[i]=='0')
        {
            i++;
        }

        return i==res.length() ? "0":res.substr(i);
    }
};