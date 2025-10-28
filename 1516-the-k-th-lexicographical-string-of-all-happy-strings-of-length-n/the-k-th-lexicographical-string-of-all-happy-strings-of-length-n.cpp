class Solution {
private:
    vector<string>res;

    vector<char>letters={'a', 'b', 'c'};

    void func(string str, int n)
    {
        if(str.length()==n)
        {
            res.push_back(str);
            return;
        }

        for(auto it: letters)
        {
            if(!str.empty() && str.back()==it)
            {
                continue;
            }

            str+=it;
            func(str, n);
            str.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        func("", n);

        if(k>res.size())
        { 
            return "";
        }

        return res[k-1];
    }
};