class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char c : num) {
            // Remove elements from stack if they are greater than current digit and we can still remove `k` elements
            while(!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            // Push current digit
            st.push(c);
        }

        // Remove remaining k digits from the end if needed
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the final string
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // Reverse since we inserted from the back
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;

        // Return the final answer or "0" if empty
        return i == ans.size() ? "0" : ans.substr(i);
    }
};
