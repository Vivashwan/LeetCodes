class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.size()!=goal.size())
        { 
            return false;
        }

        if(s==goal)
        {
            set<char>st(s.begin(), s.end());
            return st.size()<goal.size();
        }

       int i=0, j=s.size()-1;

       while(i<j && s[i]==goal[i])
       {
           i++;
       }

       while(j>i && s[j]==goal[j])
       {
           j--;
       }

       if(i<j)
       {
           swap(s[i], s[j]);
       }

       return (s==goal);
    }
};