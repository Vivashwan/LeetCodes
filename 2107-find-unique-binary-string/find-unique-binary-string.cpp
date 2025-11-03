class Solution {
private:
    vector<string>res;
    void func(string str, int n, unordered_set<string>&s)
    {
        if(str.length()==n)
        {
            res.push_back(str);
            return;
        }

        for(char v='0'; v<'2'; v++)
        {
            str+=v;

            func(str, n, s);

            str.pop_back();
        }

        return;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();

        unordered_set<string>s(nums.begin(), nums.end());

        string str="";

        func(str, n, s);

        for(auto it: res)
        {
            if(s.find(it)==s.end())
            {
                return it;
            }
        }

        return "";
    }
};