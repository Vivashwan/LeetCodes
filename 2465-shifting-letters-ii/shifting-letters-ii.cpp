class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();

        vector<int>prefix(n+1, 0);

        for(auto it: shifts)
        {
            int dir=it[2]==1? 1:-1;

            prefix[it[0]]+=dir;
            prefix[it[1]+1]-=dir;
        }

        for(int i=1; i<=n; i++)
        {
            prefix[i]+=prefix[i-1];
        }

        for(int i=0; i<n; i++)
        {
            int total=(((prefix[i]%26)+26)%26);

            int newChar=(s[i]-'a'+total)%26;

            s[i]='a'+newChar;
        }

        return s;
    }
};