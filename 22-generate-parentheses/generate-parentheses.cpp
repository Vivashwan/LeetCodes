class Solution {
private:
    vector<string>res;

    void func(string str, int countOpen, int countClose, int n)
    {
        if(countOpen==0 && countClose==0)
        {
            res.push_back(str);
        }

        if(countOpen>0)
        {
            countOpen--;
            func(str+'(', countOpen, countClose, n);
            countOpen++;
        }

        if(countClose>countOpen)
        {
            countClose--;
            func(str+')', countOpen, countClose, n);
            countClose++;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int countOpen=n, countClose=n;

        string str="";

        func(str, countOpen, countClose, n);

        return res;
    }
};