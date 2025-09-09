class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res=0;

        unordered_set<char>st;

        for(auto it: s)
        {
            st.insert(it);
        }

        for(auto it: st)
        {
            int start=s.find(it), end=s.rfind(it);

            unordered_set<char>uniques;

            for(int i=start+1; i<end; i++)
            {
                uniques.insert(s[i]);
            }

            res+=uniques.size();
        }

        return res;
    }
};