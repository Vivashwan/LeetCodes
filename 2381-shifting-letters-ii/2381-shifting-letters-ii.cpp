class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<long>prefix(n+1, 0);

        for(auto it: shifts)
        {
            int start=it[0], end=it[1], direction=it[2];

            int value = (direction==1) ? 1:-1;

            prefix[start]+=value;
            prefix[end+1]-=value;
        }

        for(int i=1; i<n; i++)
        {
            prefix[i]+=prefix[i-1];
        }

        for(int i=0; i<n; i++)
        {
            long total=prefix[i];

            total=((total % 26) + 26) % 26;

            int newChar=(s[i]-'a'+total)%26;

            s[i] = 'a'+newChar;
        }

        return s;
    }
};