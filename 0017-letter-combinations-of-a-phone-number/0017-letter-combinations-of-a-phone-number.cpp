class Solution {
private:
    vector<string>numPad={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void func(int ind, string digits, string output, vector<string>&res)
    {
        if(ind==digits.length())
        {
            res.push_back(output);
            return;
        }

        for(int i=0; i<numPad[digits[ind]-'0'].size(); i++)
        {
            output+=numPad[digits[ind]-'0'][i];
            func(ind+1, digits, output, res);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();

        if(n==0)
        {
            return {};
        }

        vector<string>res;

        string output;

        func(0, digits, output, res);

        return res;
    }
};