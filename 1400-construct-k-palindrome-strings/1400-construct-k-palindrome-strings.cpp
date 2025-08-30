class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();

        if(n<k)
        {
            return false;
        }

        unordered_map<char, int>mp;

        for(auto it: s)
        {
            mp[it]++;
        }

        int countOdd=0;

        for(auto it: mp)
        {
            if(it.second%2!=0)
            {
                countOdd++;
            }
        }

        if(countOdd>k)
        {
            return false;
        }

        return true;
    }
};