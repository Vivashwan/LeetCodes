class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        unordered_set<char>unique;

        for(auto it: s)
        {
            unique.insert(it);
        }

        for(auto it: unique)
        {
            int start = s.find(it), end = s.rfind(it);

            if(start<end)
            {
                unordered_set<char>uniques;

                for(int i=start+1; i<end; i++)
                {
                    uniques.insert(s[i]);
                }
                
                res+=uniques.size();
            }

        }

        return res;
    }
};