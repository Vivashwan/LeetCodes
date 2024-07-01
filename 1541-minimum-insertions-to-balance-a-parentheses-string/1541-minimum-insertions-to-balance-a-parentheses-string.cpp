class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        int count=0;

        stack<char>st;

        for(int i=0; i<n; i++)
        {
            if(i+1<n && s[i]==')' && s[i+1]==')' && st.empty())
            {
                count++, i++;
            }
            else if(i+1<n && s[i]==')' && s[i+1]==')')
            {
                st.pop();
                i++;
            }
            else if(s[i]==')' && st.empty())
            {
                count+=2;
            }
            else if(s[i]==')')
            {
                count++;
                st.pop();
            }
            else st.push(s[i]);
        }

        return count+st.size()*2;
    }
};