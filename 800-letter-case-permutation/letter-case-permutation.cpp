class Solution {
private:
    vector<string>res;

    void func(string s, int i, int n)
    {
        if(i==n)
        {
            res.push_back(s);
            return;
        }

        func(s, i+1, n);

        if(s[i]>='a' && s[i]<='z')
        {
            s[i]=s[i]-32;
            func(s, i+1, n);
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            s[i]=s[i]+32;
            func(s, i+1, n);
        }

        
    }
public:
    vector<string> letterCasePermutation(string s) {
        int n=s.length();

        func(s, 0, n);

        return res;
    }
};