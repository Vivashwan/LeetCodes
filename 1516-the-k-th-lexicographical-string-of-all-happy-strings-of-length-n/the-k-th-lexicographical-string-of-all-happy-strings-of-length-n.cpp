class Solution {
private:
    void func(string curr, vector<string>&res, vector<char>&ch, int n, int k)
    {
        if(res.size()==k)
        {
            return;
        }

        if(curr.size()==n)
        {
            res.push_back(curr);
            return;
        }

        for(int i=0; i<3; i++)
        {
            if(curr.size()==0 || curr[curr.size()-1]!=ch[i])
            {
                curr+=ch[i];
                func(curr, res, ch, n, k);
                curr.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<char>ch={'a', 'b', 'c'};

        string curr="";

        vector<string>res;

        func(curr, res, ch, n, k);

        if(res.size()==k)
        {
            return res.back();
        }
        
        else return "";
    }
};