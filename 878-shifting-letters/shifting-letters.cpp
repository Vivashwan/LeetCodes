class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();

        long total=0;

        for(int i=n-1; i>=0; i--)
        {
            s[i]=((s[i]-'a')+(shifts[i]+total)%26)%26+'a';
            total+=shifts[i];
        }

        return s;
    }
};