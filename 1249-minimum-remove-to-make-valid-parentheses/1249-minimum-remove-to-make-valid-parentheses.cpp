class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();

        stack<pair<char, int>>st;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='(' || s[i]==')')
            {
                if(st.empty()) 
                {
                    st.push({s[i], i});
                }  
                else if(s[i]==')' && st.top().first=='(')
                {
                    st.pop();
                }
                else st.push({s[i], i});
            }
        }

        vector<int>visited(n, 0);

        while(!st.empty())
        {
            visited[st.top().second]=1;
            st.pop();
        }

        string str="";

        for(int i=0; i<n; i++)
        {
            if(visited[i]!=1)
            {
                str+=s[i];
            }
        }

        return str;
    }
};