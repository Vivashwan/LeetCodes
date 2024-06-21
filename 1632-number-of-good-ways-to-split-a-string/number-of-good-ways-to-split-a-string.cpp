class Solution {
public:
    int numSplits(string s) {
        int n = s.size();

        unordered_map<char, int>mp1, mp2;

        for(auto it: s)
        {
            mp1[it]++;
        }

        int res=0;

        for(int i=0; i<n; i++)
        {
            char ch = s[i];

            mp2[ch]++;

            mp1[ch]--;

            if(mp1[ch]==0)
            {
                mp1.erase(ch);
            }

            if(mp1.size()==mp2.size())
            {
                res++;
            }
        }

        return res;
    }
};