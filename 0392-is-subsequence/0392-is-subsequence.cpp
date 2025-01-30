class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPointer=0, tPointer=0, n=s.length(), m=t.length();

        while(sPointer<n && tPointer<m)
        {
            if(s[sPointer]==t[tPointer])
            {
                sPointer++;
            }

            tPointer++;
        }

        return sPointer==n;
    }
};