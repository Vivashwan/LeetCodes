class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        unordered_map<char, int>mp;

        int res=-1;

        for(int i=0; i<n; i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                res=max(res, i-1-mp[s[i]]);
            }
            else
            {
                mp[s[i]]=i;
            }
        }

        return res;
    }
};