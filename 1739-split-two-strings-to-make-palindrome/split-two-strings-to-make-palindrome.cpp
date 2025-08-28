class Solution {
private:
    bool checkPalindrome(string &a, string &b) 
    {
        int i=0, j=a.size()-1;

        while(i<j && a[i]==b[j]) 
        {
            i++, j--;
        }

        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }
    
    bool isPalindrome(string &s, int i, int j) 
    {
        while(i<j) 
        {
            if(s[i]!=s[j]) 
            {
                return false;
            }

            i++, j--;
        }

        return true;
    }

public:
    bool checkPalindromeFormation(string a, string b) {
        return checkPalindrome(a, b) || checkPalindrome(b, a);
    }
};