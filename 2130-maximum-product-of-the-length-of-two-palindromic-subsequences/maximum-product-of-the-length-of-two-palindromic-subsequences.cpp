class Solution {
private:
    int maxim=INT_MIN;

    bool checkPalindrome(string s) 
    { 
        int i=0, j=s.length()-1; 

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

    void func(int ind, int n, string& s, string s1, string s2)
    {
        if(ind==n)
        {
            if(checkPalindrome(s1) && checkPalindrome(s2))
            {
                int size1=s1.length(), size2=s2.length();
                maxim=max(maxim, size1*size2);
            }

            return;
        }

        func(ind+1, n, s, s1+s[ind], s2);
        func(ind+1, n, s, s1, s2+s[ind]);
        func(ind+1, n, s, s1, s2);
    }

public:
    int maxProduct(string s) {
        int n=s.length();

        string s1="", s2="";

        func(0, n, s, s1, s2);

        return maxim;
    }
};