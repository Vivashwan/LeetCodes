class Solution {
public:
    char findTheDifference(string s, string t) {
        int xorVal=0;

        for(auto it: s)
        {
            xorVal^=it-'a';
        }

        for(auto it: t)
        {
            xorVal^=it-'a';
        }

        return xorVal+'a';
    }
};