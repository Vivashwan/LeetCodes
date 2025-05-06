class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();

        if(n==1)
        {
            return s;
        }

        vector<bool>visited(26, false);
        vector<int>lastOcc(26, -1);

        string str="";

        for(int i=0; i<n; i++)
        {
            lastOcc[s[i]-'a']=i;
        }

        for(int i=0; i<n; i++)
        {
            if(!visited[s[i]-'a'])
            {
                while(!str.empty() && s[i]<str.back() && i<lastOcc[str.back()-'a'])
                {
                    visited[str.back()-'a']=false;
                    str.pop_back();
                }

                str+=s[i];
                visited[s[i]-'a']=true;
            }
        }

        return str;
    }
};