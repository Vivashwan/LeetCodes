class Solution {
private:
    bool isPalindrome(string &s, int left, int right) 
    {
        while(left<right) 
        {
            if(s[left]!=s[right])
            {    
                return false;
            }
            left++, right--;
        }

        return true;
    }

    int func(string &s, int left, int n, vector<int>&dp) 
    {
        if(left==n)
        { 
            return -1;
        }

        if(dp[left]!=-1)
        {
            return dp[left];
        }

        int minCuts=INT_MAX;

        for(int right=left; right<n; right++) 
        {
            if(isPalindrome(s, left, right)) 
            {
                int cuts=1+func(s, right+1, n, dp);
                minCuts=min(minCuts, cuts);
            }
        }

        return dp[left] = minCuts;
    }

public:
    int minCut(string s) {
        int n=s.length();

        vector<int>dp(n+1, -1);
        return func(s, 0, n, dp);
    }
};
