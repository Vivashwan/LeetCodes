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

                int j=i;
                while(j<n && pattern[j]=='D') 
                {
                    st.push(count+'0');
                    count++;
                    j++;
                }

                st.push(count+'0');
                count++;

                while(!st.empty()) 
                {
                    res+=st.top();
                    st.pop();
                }

                i=j;
            }
        }

        if(res.size()<n+1) 
        {
            res+=count+'0';
        }

        return res;
    }
};
