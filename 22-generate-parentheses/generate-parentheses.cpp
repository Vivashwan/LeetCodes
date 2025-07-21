class Solution {
private:
    void func(int i, int j, string temp, int n, vector<string>&res)
    {
        if(i==n && j==n)
        {
            res.push_back(temp);
            return;
        }

        if(i<n)
        {
            func(i+1, j, temp+'(', n, res);
        }

        if(i>j)
        {
            func(i, j+1, temp+')', n, res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;

        func(0, 0, "", n, res);

        return res;
    }
};