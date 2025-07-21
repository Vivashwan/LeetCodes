class Solution {
private:
    void func(int ind, string& s, int n, vector<string>&res)
    {
        if(ind==n)
        {
            res.push_back(s);
            return;
        }

        func(ind+1, s, n, res);

        if(isalpha(s[ind]))
        {
            s[ind]^=32;

            func(ind+1, s, n, res);

            s[ind]^=32;
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        int n=s.length();

        vector<string>res;

        func(0, s, n, res);

        return res;
    }
};