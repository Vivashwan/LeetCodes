class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        int count = 1;
        string res = "";

        for (int i = 0; i < n; i++) {
            if (pattern[i] == 'I') {
                res += count + '0';
                count++;
            } else {
                stack<char> st;

                int j = i; // temp pointer to scan D's
                while (j < n && pattern[j] == 'D') {
                    st.push(count + '0');
                    count++;
                    j++;
                }

                // push the final number after the run of D's
                st.push(count + '0');
                count++;

                while (!st.empty()) {
                    res += st.top();
                    st.pop();
                }

                i = j; // <-- let outer loop i skip directly to first non-D index
            }
        }

        // if we somehow missed the last count (pattern ends with I)
        if (res.size() < n + 1) res += count + '0';

        return res;
    }
};
