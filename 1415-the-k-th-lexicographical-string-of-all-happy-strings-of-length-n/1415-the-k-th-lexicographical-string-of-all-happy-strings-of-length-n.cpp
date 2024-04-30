class Solution {
private:
    void func(vector<string>&ans, string curr, int n, int k, vector<char>&ch)
    {
        if(ans.size()==k)
        {
            return;
        }

        if(curr.size()==n)
        {
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<3; i++)
        {
            if(curr.size()==0 || curr[curr.size()-1]!=ch[i])
            {
                curr+=ch[i];

                func(ans, curr, n, k, ch);

                curr.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<char>ch = {'a', 'b', 'c'};

        string curr = "";

        vector<string>ans;

        func(ans, curr, n, k, ch);

        if(ans.size()==k)
        {
            return ans.back();
        }
        else return "";
    }
};