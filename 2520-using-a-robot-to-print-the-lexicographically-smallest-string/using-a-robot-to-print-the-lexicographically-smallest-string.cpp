class Solution {
public:
    string robotWithString(string s) {
        vector<int>freq(26, 0);

        for(auto it: s)
        {
            freq[it-'a']++;
        }

        stack<char>st;

        string res;

        char currMin='a';

        while(currMin<='z' && freq[currMin-'a']==0)
        {
            currMin++;
        }

        for(auto it: s)
        {
            st.push(it);
            freq[it-'a']--;

            while(currMin<='z' && freq[currMin-'a']==0)
            {
                currMin++;
            }

            while(!st.empty() && st.top()<=currMin)
            {
                res.push_back(st.top());
                st.pop();
            }
        }

        return res;
    }
};