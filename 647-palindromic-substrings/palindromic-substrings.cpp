class Solution {
private:
    void expand(string s, int n, int left, int right, int &count) 
    {
        while(left>=0 && right<n && s[left]==s[right]) 
        {
            count++;
            left--, right++;
        }
    }

public:
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;

        for(int i=0; i<n; i++) 
        {
            expand(s, n, i, i, count);    
            expand(s, n, i, i+1, count); 
        }

        return count;
    }
};
