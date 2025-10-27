class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        int count=1;

        string res="";

        for(int i=0; i<n; i++)
        {
            if(pattern[i]=='I')
            {
                res+=count+'0';
                count++;
            }
            else
            {
                stack<char>st;

                while(i<n && pattern[i]=='D')
                {
                    cout<<count<<" "<<i<<endl;
                    st.push(count+'0');
                    count++;
                    i++;
                }

                cout<<count<<" "<<i<<endl;

                st.push(count+'0');
                count++;

                while(!st.empty())
                {
                    res+=st.top();
                    st.pop();
                }
            }
        }

        if(res.size()<n+1) 
        {
            res+=count+'0';
        }

        return res;
    }
};