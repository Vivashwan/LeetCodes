class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        int len1 = s.length(), len2 = t.length();
        vector<vector<int>> same(len1+1, vector<int>(len2+1, 0)); 
        auto differ = same;
        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(s[i-1] == t[j-1])  
                {
                    same[i][j] = 1 + same[i-1][j-1]; 
                    differ[i][j] = differ[i-1][j-1]; 
                }
                else  
                    differ[i][j] = same[i-1][j-1] + 1;  
                ans += differ[i][j];  
            }
        }
        return ans;
    }
};