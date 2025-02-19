class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n=s.size();
        int maxLen=0; 

        vector<int>dp(26, 0);

        for(int i=0; i<n; i++) 
        {
            if(i>0 && (s[i]-s[i-1]+26)%26==1) 
            {
                maxLen++;
            } 
            else maxLen=1;
            
            int index = s[i]-'a';
            dp[index] = max(dp[index], maxLen); 
        }

        int res=0;

        for(int len: dp) 
        {
            res+=len;
        }

        return res;
    }
};