class Solution {
private:
    bool isValid(string &str)
    {
        if (str[0] == '0') return false;
        int num = stoi(str);
        return num >= 1 && num <= 26;
    }
    int func(string &s, int ind, int n, vector<int>&dp)
    {
        if(ind==n)
        {
            return 1;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        int count = 0;

        string str = "";

        for(int i=ind; i<n && i<ind+2; i++)
        {
            str+=s[i];

            if(isValid(str))
            {
                count+=func(s, i+1, n, dp);
            }
        }   

        return dp[ind]=count;
    }
public:
    int numDecodings(string s) {
        int n = s.length();

        vector<int>dp(n, -1);

        return func(s, 0, n, dp);
    }
};