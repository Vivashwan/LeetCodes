class Solution {
public:
    bool isPalindrome(string s) {
        string str="", str1="";
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9')
            {
                str+=tolower(s[i]);
                str1+=tolower(s[i]);
            }
        }


        if(str.size()<=1)
        {
            return true;
        }


        reverse(str.begin(), str.end());

        if(str==str1)
        {
            return true;
        }

        return false;
    }
};