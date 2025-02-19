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

    int func(string &s, int n, vector<int>&dp) 
    {
        dp[n]=-1;

        for(int left=n-1; left>=0; left--)
        {
            int minCuts=INT_MAX;

            for(int right=left; right<n; right++) 
            {
                if(isPalindrome(s, left, right)) 
                {
                    int cuts=1+dp[right+1];
                    minCuts=min(minCuts, cuts);
                }
            }

            dp[left] = minCuts;
        }

        return dp[0];
    }

public:
    int minCut(string s) {
        int n=s.length();

        vector<int>dp(n+1, 0);
        return func(s, n, dp);
    }
};
