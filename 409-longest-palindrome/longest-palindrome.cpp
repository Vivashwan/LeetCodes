class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>mp;

        for(auto it: s)
        {
            mp[it]++;
        }

        int count=0;
        bool oddFound=false;

        for(auto it:mp)
        {
            count+=(it.second/2)*2;
            if(it.second%2!=0)
            {
                oddFound=true;;
            }
        }

        if(oddFound==true)
        {
            count++;
        }

        return count;
    }
};