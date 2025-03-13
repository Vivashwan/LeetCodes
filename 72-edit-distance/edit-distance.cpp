class Solution {
private:
    int func(string& word1, string& word2, int n, int m, int ind1, int ind2, vector<vector<int>>&dp)
    {
        if(ind1>=n)
        {
            return m-ind2;
        }

        if(ind2>=m)
        {
            return n-ind1;
        }

        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }

        if(word1[ind1]==word2[ind2])
        {
            return func(word1, word2, n, m, ind1+1, ind2+1, dp);
        }            

        return dp[ind1][ind2] = 1+min({func(word1, word2, n, m, ind1+1, ind2, dp), func(word1, word2, n, m, ind1, ind2+1, dp), func(word1, word2, n, m, ind1+1, ind2+1, dp)});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return func(word1, word2, n, m, 0, 0, dp);   
    }
};