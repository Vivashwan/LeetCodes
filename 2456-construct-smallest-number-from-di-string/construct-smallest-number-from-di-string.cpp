class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        int count=1;

        string str="";

        for(int i=0; i<n; i++)
        {
            if(pattern[i]=='I')
            {
                str+=(count+'0');
                count++;
            }
            else
            {
                int j=i;

                stack<int>st;

                while(j<n && pattern[j]=='D')
                {
                    st.push(count);
                    count++;
                    j++;
                }

                st.push(count);
                count++;

                while(!st.empty())
                {
                    str+=st.top()+'0';
                    st.pop();
                }

                i=j;
            }
        }

        if(str.length()<n+1)
        {
            str+=count+'0';
        }

        return str;
    }
};