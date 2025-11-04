class Solution {
private:
    bool isPalindrome(string str)
    {
        int i=0, j=str.length()-1;

        while(i<j)
        {
            if(str[i]!=str[j])
            {
                return false;
            }

            i++, j--;
        }

        return true;
    }

    vector<vector<string>>res;

    void func(vector<string>temp, string s, int ind, int n)
    {
        if(ind==n)
        {
            res.push_back(temp);
            return;
        }

        string str="";

        for(int i=ind; i<n; i++)
        {
            str+=s[i];

            if(isPalindrome(str))
            {
                temp.push_back(str);
                func(temp, s, i+1, n);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.length();

        vector<string>temp;

        string str="";

        for(int i=0; i<n; i++)
        {
            str+=s[i];

            if(isPalindrome(str))
            {
                temp.push_back(str);
                func(temp, s, i+1, n);
                temp.pop_back();
            }
        }

        return res;
    }
};