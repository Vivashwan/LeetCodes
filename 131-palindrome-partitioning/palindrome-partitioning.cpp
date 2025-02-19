class Solution {
private:
    bool isPalindrome(string s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
            {
                return false;
            }
            start++, end--;
        }

        return true;
    }

    void func(int ind, string s, vector<vector<string>>&res, vector<string>&temp, int n)
    {
        if(ind==n)
        {
            res.push_back(temp);
            return;
        }

        for(int i=ind; i<n; i++)
        {
            if(isPalindrome(s, ind, i))
            {
                temp.push_back(s.substr(ind, i-ind+1));
                func(i+1, s, res, temp, n);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;

        vector<string>temp;

        func(0, s, res, temp, s.size());

        return res;
    }
};