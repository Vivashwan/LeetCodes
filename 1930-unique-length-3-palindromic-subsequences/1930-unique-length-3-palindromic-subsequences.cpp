class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>temp;
        int ans=0;

        for(auto &c:s)
        {
            temp.insert(c);
        }

        for(auto letter:temp)
        {
            int first=-1;
            int last=-1;

            for(int k=0; k<s.size(); k++)
            {
                if(s[k]==letter)
                {
                    if(first==-1)
                    {
                        first=k;
                    }
                    
                    last=k;
                }
            }

            unordered_set<char>st;

            for(int i=first+1; i<last; i++)
            {
                st.insert(s[i]);
            }

            ans+=st.size();
        }

        return ans;
    }
};