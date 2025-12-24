class Solution {
private:
    string func(string& s, string substring, int x, int &count)
    {
        stack<char>st;

        for(char c: s)
        {
            if(!st.empty() && st.top()==substring[0] && c==substring[1])
            {
                st.pop();
                count+=x;
            }
            else
            {
                st.push(c);
            }
        }

        string str="";

        while(!st.empty())
        {
            str += st.top();
            st.pop();
        }

        reverse(str.begin(), str.end());
        return str;
    }

public:
    int maximumGain(string s, int x, int y) {
        int count=0;

        if(x>=y)
        {
            s=func(s, "ab", x, count);
            s=func(s, "ba", y, count);
        }
        else
        {
            s=func(s, "ba", y, count);
            s=func(s, "ab", x, count);
        }

        return count;
    }
};
